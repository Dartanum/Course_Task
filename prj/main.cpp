#include "player.h"
#include "textureLoader.h"
#include "planet.h"
#include "asteroid.h"
#include "weapon.h"
#include "spawner.h"
#include "Menu.h"
#include "settings.h"
#include "TopResults.h"

#include <list>
#define PI 3.14159265

using namespace sf;

int main(int args, char* argv[])
{
  ContextSettings windowSettings;
  windowSettings.antialiasingLevel = 16; //установка уровня сглаживания фигур
  RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Star wasteland", Style::Fullscreen, windowSettings);
  Vector2u screen = window.getSize();
  float screenRatio = float(screen.x) / float(screen.y);
  double FPS = 60;
  window.setFramerateLimit(FPS);
  std::string prefix = "src";
  //---------------------------------ТЕКСТУРЫ И ШРИФТЫ------------------------------------------
  textureLoader tl;
  Font font, monoFont;
  if (font.loadFromFile(prefix + "/fonts/17734.otf"))
    prefix = "src";
  else if (!font.loadFromFile(prefix + "/fonts/17734.otf"))
    prefix = "../" + prefix;
  else prefix = "../" + prefix;
  font.loadFromFile(prefix + "/fonts/17734.otf");
  monoFont.loadFromFile(prefix + "/fonts/monosize.ttf");
  std::vector<std::string> textures;
  for (ptrdiff_t i = 0; i < 2; i++) {
    textures.push_back(prefix + "/textures/Backgrounds/back" + std::to_string(i + 1) + ".jpg");
  }
  tl.loader(Objects::BACKGROUND, textures);
  std::map<std::string, std::string> menuSource;
  menuSource["mainTile"] = prefix + "/textures/Menu/blueSheet.png";
  menuSource["panel"] = prefix + "/textures/Menu/panel.png";
  menuSource["logo"] = prefix + "/textures/logo.png";
  menuSource["slider"] = prefix + "/textures/Menu/slider.png";
  tl.loderMenu(menuSource);
  Texture* dest_effect_planet = new Texture();
  std::vector<std::string> paths;
  std::vector<std::string> paths1;
  std::vector<std::string> paths2;
  dest_effect_planet->loadFromFile(prefix + "/textures/Destroy_effects_planet/dest_effect.png");
  for (ptrdiff_t i = 0; i < 18; i++) {
    paths.push_back(prefix + "/textures/planet/planet" + std::to_string(i) + ".png");
  }
  for (ptrdiff_t i = 0; i < 9; i++) {
    std::string s = prefix + "/textures/Destroy_effects/regularExplosion0" + std::to_string(i) + ".png";
    paths1.push_back(s);
  }
  for (ptrdiff_t i = 0; i < 8; i++) {
    paths2.push_back(prefix + "/textures/asteroid/meteor" + std::to_string(i) + ".png");
  }
  tl.loader(Objects::DEST_EFFECT, paths1);
  std::string path = prefix + "/textures/player/player.png";
  tl.loader(Objects::PLAYER, path);
  tl.loader(Objects::PLANET, paths);
  tl.loader(Objects::ASTEROID, paths2);
  path = prefix + "/textures/weapon/laserBlue.png";
  tl.loader(Objects::WEAPON, path);
  path = prefix + "/textures/UI/shield.png";
  tl.loader(Objects::UI, path);

  std::string settingsPath = prefix + "/text/settings.ini";
  std::string recordsPath = prefix + "/text/records.ini";
  settings settingsGame(settingsPath, 15);
  TopResults records(recordsPath, 5);
  settingsGame.read();
  records.read();
  Menu main_menu(settingsGame, records, tl, screen, font, monoFont, prefix);
  if (main_menu.menu(window)) return 0;
  //---------------------------------МУЗЫКА И ЗВУКИ---------------------------------
  SoundBuffer boomBuffer;
  if (!boomBuffer.loadFromFile(prefix + "/sounds/Boom.ogg"))
    return -1;
  boomBuffer.loadFromFile(prefix + "/sounds/Boom.ogg");
  Sound boom(boomBuffer);
  SoundBuffer planetBuffer;
  if (!planetBuffer.loadFromFile(prefix + "/sounds/destroy_planet.ogg"))
    return -1;
  planetBuffer.loadFromFile(prefix + "/sounds/destroy_planet.ogg");
  Sound destroy_planet(planetBuffer);
  boom.setVolume(10);
  SoundBuffer shootBuffer;
  if (!shootBuffer.loadFromFile(prefix + "/sounds/shoot.ogg"))
    return -1;
  shootBuffer.loadFromFile(prefix + "/sounds/shoot.ogg");
  Sound shoot(shootBuffer);
  SoundBuffer bornBuffer;
  if (!bornBuffer.loadFromFile(prefix + "/sounds/born.ogg"))
    return -1;
  bornBuffer.loadFromFile(prefix + "/sounds/born.ogg");
  Sound bornSound(bornBuffer);
  Music music;
  if (!music.openFromFile(prefix + "/music/spaceMusic.ogg"))
    return -1;
  music.openFromFile(prefix + "/music/spaceMusic.ogg");

  //---------------------------------ПЕРЕМЕННЫЕ ИГРЫ-------------------------------
  Text lifetime;
  Text pointCount;
  RectangleShape background; //фон игры
  pointCount.setFont(font);
  lifetime.setFont(font);
  int charSize = 20 * screenRatio;
  float speed = 0.1;
  float speedWeapon = speed * 3.0f;
  float angularSpeed = 3;
  float maxRadPlanet = (85.0f * screenRatio);
  float minRadPlanet = (56.0f * screenRatio);
  int minPlanetKD = 5;
  int maxPlanetKD = 15;
  float minDiametreAst = 50.0f * screenRatio;
  float maxDiametreAst = 60.0f * screenRatio;
  int gameTime = 0; //прошедшое в секундах время игры
  int points = 0; //количество очков
  Clock gameTimeClock; //часы игры
  Clock clock;
  background.setSize(Vector2f(screen.x, screen.y));
  bool life = true; //жив ли игрок
  bool isEnd = false;
  bool spaceClick = false; //нажата ли кнопка space
  float weaponKD = sqrt(screen.x * screen.x + screen.y * screen.y) / (speedWeapon * 3000); //время, через которое бластер обновляется
  float currentFrame = 0; //текущий кадр
  int timeLastFrame = 0;
  float radius;
  int area;
  //установка точек-границ спавна планет
  std::vector<Vector2f> spawnPointsPlanet;
  std::map<int, Vector2f> useSpawnPointsPlanet;
  for (ptrdiff_t i = 0; i < 3; i++) {
    spawnPointsPlanet.push_back(Vector2f(screen.x / 3 * i, 0));
    spawnPointsPlanet.push_back(Vector2f(screen.x / 3 * i, screen.y / 2));
  }
  background.setTexture(tl.backgrounds[1]);
  lifetime.setCharacterSize(charSize);
  lifetime.setPosition(screen.x - screen.x / 10.0f, screen.y / 100.0f);
  pointCount.setCharacterSize(charSize);
  pointCount.setPosition(screen.x - screen.x / 10.0f, lifetime.getPosition().y + charSize + screen.y / 100.0f);

  Spawner spawner;
  Player player(tl.players[0], speed, angularSpeed, screen);
  Weapon weapon(tl.weapons[0], speedWeapon, weaponKD, screenRatio);
  std::list<Asteroid*> asteroids;
  std::list<Asteroid*>::iterator it;
  std::list<Planet*> planets;
  std::list<Planet*>::iterator it_p;
  int choice = 0;
  bool go = false;
  do {
    if (!life) {
      music.stop();
      if (choice == 0)
        choice = main_menu.endGameMenu(window, points, gameTime, background);
      switch (choice) {
      case 1:
        return 0;
        break;
      case 2:
        if (main_menu.menu(window))
          return 0;
      case 3:
        choice = 0;
        life = true;
        isEnd = false;
        gameTimeClock.restart();
        spaceClick = false;
        gameTime = 0;
        points = 0;
        clock.restart();
        spaceClick = false;
        player.standartCondition();
        player.player.setPosition(screen.x / 2, screen.y / 2);
        player.player.setRotation(0);
        player.anim_end = false;
        break;
      }
    }
    settingsGame.read();
    records.read();
    music.setVolume(settingsGame.musicVolume);
    if (settingsGame.soundIsOn) {
      boom.setVolume(settingsGame.soundVolume);
      destroy_planet.setVolume(settingsGame.soundVolume);
      shoot.setVolume(settingsGame.soundVolume);
      bornSound.setVolume(settingsGame.soundVolume);
    }
    else {
      boom.setVolume(0);
      destroy_planet.setVolume(0);
      shoot.setVolume(0);
      bornSound.setVolume(0);
    }
    //-------------------------------------------------START GAME------------------------------------------------------------------------------
    asteroids.push_back(new Asteroid(spawner.generator(minDiametreAst, maxDiametreAst), spawner.generator(speed, 0.16f),
      screen, spawner.generatorAsteroids(screen), 5, tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]));
    asteroids.push_back(new Asteroid(spawner.generator(minDiametreAst, maxDiametreAst), spawner.generator(speed, 0.16f),
      screen, spawner.generatorAsteroids(screen), 20, tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]));
    asteroids.push_back(new Asteroid(spawner.generator(minDiametreAst, maxDiametreAst), spawner.generator(speed, 0.16f),
      screen, spawner.generatorAsteroids(screen), 30, tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]));
    asteroids.push_back(new Asteroid(spawner.generator(minDiametreAst, maxDiametreAst), spawner.generator(speed, 0.16f),
      screen, spawner.generatorAsteroids(screen), 60, tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]));
    asteroids.push_back(new Asteroid(spawner.generator(minDiametreAst, maxDiametreAst), spawner.generator(speed, 0.16f),
      screen, spawner.generatorAsteroids(screen), 120, tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]));
    radius = spawner.generator(minRadPlanet, maxRadPlanet);
    area = spawner.chooseArea(spawnPointsPlanet, useSpawnPointsPlanet);
    planets.push_back(new Planet(radius, spawner.generator(5.0f, 10.0f), tl.planets[spawner.generator(0, tl.planets.size() - 1)],
      spawner.generatorPlanets(screen, spawnPointsPlanet, radius, area), radius / 10, spawner.generator(minPlanetKD, maxPlanetKD), area, font, tl.ui[0], dest_effect_planet));
    radius = spawner.generator(minRadPlanet, maxRadPlanet);
    area = spawner.chooseArea(spawnPointsPlanet, useSpawnPointsPlanet);
    planets.push_back(new Planet(radius, spawner.generator(5.0f, 10.0f), tl.planets[spawner.generator(0, tl.planets.size() - 1)],
      spawner.generatorPlanets(screen, spawnPointsPlanet, radius, area), radius / 10, spawner.generator(minPlanetKD, maxPlanetKD), area, font, tl.ui[0], dest_effect_planet));
    //-------------------------------ИГРОВОЙ ПРОЦЕСС---------------------------------------------------------------
    while (window.isOpen())
    {
      Minimizer::minimizeWindow(window);
      //проигрывание музыки
      if (!music.getStatus() && settingsGame.musicIsOn) {
        music.play();
      }
      float time = clock.getElapsedTime().asMicroseconds();
      clock.restart();
      time /= 800;
      player.standartCondition();
      Event event;
      if (life) {
        gameTime = gameTimeClock.getElapsedTime().asSeconds();
      }
      while (window.pollEvent(event))
      {
        if (event.type == Event::Closed)
          window.close();
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          life = false;
          choice = 2;
        }
      }
      if (Keyboard::isKeyPressed(Keyboard::A) && life) {
        player.flyLeft(time);
      }
      if (Keyboard::isKeyPressed(Keyboard::D) && life) {
        player.flyRight(time);
      }
      if (Keyboard::isKeyPressed(Keyboard::W) && life) {
        player.flyForward(time, currentFrame);
      }
      if (Keyboard::isKeyPressed(Keyboard::S) && life) {
        player.flyBack(time);
      }
      if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S) && life) {
        player.flyForwardAndBack();
      }
      if (Keyboard::isKeyPressed(Keyboard::Space) && life) {
        if (!spaceClick && weapon.getIsMove()) {
          spaceClick = true;
          weapon.clock.restart();
          shoot.play();
        }
      }
      //--------------------------------ИНФОРМАЦИЯ--------------------------------------------------
      std::ostringstream gameTimeString, playerPointsString;
      gameTimeString << gameTime;
      playerPointsString << points;
      lifetime.setString("Time: " + gameTimeString.str());
      pointCount.setString("Points: " + playerPointsString.str());
      if ((lifetime.getGlobalBounds().left + lifetime.getGlobalBounds().width) >= screen.x)
        lifetime.setPosition(lifetime.getPosition().x - charSize, lifetime.getPosition().y);
      if ((pointCount.getGlobalBounds().left + pointCount.getGlobalBounds().width) >= screen.x)
        pointCount.setPosition(pointCount.getPosition().x - charSize, pointCount.getPosition().y);
      //------------------------------ПОВЫШЕНИЕ СЛОЖНОСТИ-------------------------------------------
      if (gameTime != 0 && gameTime % 30 == 0 && timeLastFrame != gameTime) {
        timeLastFrame = gameTime;
        for (it = asteroids.begin(); it != asteroids.end(); it++) {
          if ((*it)->speed < speed * 2.5f)
            (*it)->updateSpeed((*it)->speed * 1.1);
        }
        minPlanetKD += 1;
        maxPlanetKD += 1;
      }
      //---------------------------------НАЧАЛО ОТРИСОВКИ-------------------------------------------
      window.clear();
      window.draw(background);
      if (life)
        window.draw(player.player);
      if (!life && !player.anim_end) {
        player.Destroy(tl.dest_effect);
        window.draw(player.dest);
      }
      else if(player.anim_end) isEnd = true;
      //-----------------------------------ПЛАНЕТЫ----------------------------------------------------
      for (it_p = planets.begin(); it_p != planets.end(); it_p++) {
        //вывод хп планеты и значка прочности
        (*it_p)->Transparency(player.player);
        if ((*it_p)->born) {
          window.draw((*it_p)->icon);
          (*it_p)->hpView.setString(std::to_string((*it_p)->currentHp) + " / " + std::to_string((*it_p)->hp));
          window.draw((*it_p)->hpView);
        }
        //смерть планеты
        if ((*it_p)->DestroyListener(gameTime))
          destroy_planet.play();
        if ((*it_p)->destroy == true) {
          (*it_p)->Destroy(5, 4, Vector2f(0, 122), 130);
          window.draw((*it_p)->planet);
        }
        if ((*it_p)->currentHp <= 0 && !(*it_p)->destroy) {
          radius = spawner.generator(minRadPlanet, maxRadPlanet);
          useSpawnPointsPlanet.erase((*it_p)->occupiedArea);
          area = spawner.chooseArea(spawnPointsPlanet, useSpawnPointsPlanet);
          (*it_p)->Die(radius, spawner.generator(5.0f, 10.0f), tl.planets[spawner.generator(0, tl.planets.size() - 1)],
            spawner.generatorPlanets(screen, spawnPointsPlanet, radius, area), radius / 10, spawner.generator(minPlanetKD, maxPlanetKD), area);
          continue;
        }
        //спавн планеты
        if (!(*it_p)->born && (*it_p)->deathTime + (*it_p)->spawnKD < gameTime) {
          (*it_p)->Spawn();
          window.draw((*it_p)->planet);
          //проигрывание звука спавна
          if ((*it_p)->beginSpawn)
            bornSound.play();
          continue;
        }
        else {
          (*it_p)->spawnClock.restart();
        }
        (*it_p)->Rotation();
        if ((*it_p)->born == true || (*it_p)->destroy)
          window.draw((*it_p)->planet);
      }
      //------------------------------------БЛАСТЕР-------------------------------------------------
      //перезарядка снаряда
      if (weapon.clock.getElapsedTime().asSeconds() > weaponKD) {
        spaceClick = false;
        weapon.update();
        weapon.setIsMove(true);
      }
      //перемещение и рисование снаряда
      if (spaceClick && weapon.getIsMove()) {
        window.draw(weapon.weapon);
        weapon.Move(player);
      }
      //--------------------------------------АСТЕРОИДЫ---------------------------------------------
      for (it = asteroids.begin(); it != asteroids.end(); it++) {
        //сброс времени при первом появлении астероида
        if ((*it)->spawnTime <= gameTime && !(*it)->getExist()) {
          (*it)->clock.restart();
          (*it)->setExist(true);
        }
        //первое появление астероида
        if ((*it)->spawnTime <= gameTime && (*it)->getExist()) {
          (*it)->setAsteroidMove(true);
          window.draw((*it)->asteroid);
        }
        //перемещение астероида
        if ((*it)->getAsteroidMove()) (*it)->Move(player);
        //столкновение снаряда с астероидом
        if (weapon.weapon.getGlobalBounds().intersects((*it)->asteroid.getGlobalBounds()) && (*it)->getAsteroidMove()) {
          (*it)->dest_pos = (*it)->asteroid.getPosition();
          (*it)->dest_anim_clock.restart();
          (*it)->destroy = true;
          (*it)->update(spawner.generatorAsteroids(screen), tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]);
          weapon.update();
          weapon.setIsMove(false);
          (*it)->setAsteroidMove(false);
          points += 100;
          boom.play();
        }
        //анимация уничтожения астероида
        if ((*it)->destroy) {
          (*it)->Destroy(tl.dest_effect);
          window.draw((*it)->dest_sprite);
        }
        //перезарядка астероида
        if ((*it)->clock.getElapsedTime().asSeconds() > (*it)->getKD() && (*it)->getExist()) {
          (*it)->setAsteroidMove(true);
          (*it)->update(spawner.generatorAsteroids(screen), tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]);
        }
        //столкновение астероида с планетой
        for (it_p = planets.begin(); it_p != planets.end(); it_p++) {
          if ((*it_p)->Intersects((*it)->asteroid) && (*it_p)->born) {
            (*it)->dest_pos = (*it)->asteroid.getPosition();
            (*it)->dest_anim_clock.restart();
            (*it)->destroy = true;
            (*it)->update(spawner.generatorAsteroids(screen), tl.asteroids[spawner.generator(0, tl.asteroids.size() - 1)]);
            (*it)->setAsteroidMove(false);
            (*it_p)->currentHp -= 1;
            boom.play();
          }
        }
      }
      //столкновение игрока с астероидом
      if (life) {
        RectangleShape body(Vector2f(player.player.getLocalBounds().width / 1.5, player.player.getLocalBounds().height / 1.5));
        body.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);
        body.setRotation(player.player.getRotation());
        body.setPosition(player.getPos());
        for (it = asteroids.begin(); it != asteroids.end(); it++) {
          if (body.getGlobalBounds().intersects((*it)->asteroid.getGlobalBounds())) {
            life = false;
            player.dest_anim_clock.restart();
            player.pos_die = Vector2f(player.getPos().x - player.player.getGlobalBounds().width / 2, player.getPos().y - player.player.getGlobalBounds().height / 2);
            boom.play();
            break;
          }
        }
      }
      window.draw(lifetime);
      window.draw(pointCount);
      window.display();
      if (isEnd) {
        for (it = asteroids.begin(); it != asteroids.end(); it++) {
          delete (*it);
        }
        for (it_p = planets.begin(); it_p != planets.end(); it_p++) {
          delete (*it_p);
        }
        asteroids.clear();
        planets.clear();
        useSpawnPointsPlanet.clear();
        break;
      }
    }
  } while (isEnd);
  return 0;
}
