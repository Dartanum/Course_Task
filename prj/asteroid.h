#ifndef ASTEROID_H
#define ASTEROID_H
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <math.h>

#include "player.h"
#include "textureLoader.h"

using namespace sf;
///@brief класс астероидов
class Asteroid {
public:
	///диаметр астероида
	float diametre;
	///скорость полета астероида
	float speed;
	///время в секундах, через которое астероид пропадет
	float KD;
	///время первого появления в секундах
	int spawnTime;
	///спрайт, на который накладываются текстуры взрыва
	Sprite dest_sprite;
	///объект астероида
	RectangleShape asteroid;
	Clock clock;
	///таймер для анимации уничтожения
	Clock dest_anim_clock;
	///позиция, на которой астероид был уничтожен
	Vector2f dest_pos;
	///уничтожен астероид или нет
	bool destroy;

	Asteroid() = default;
	Asteroid(Asteroid&) = default;
	/**
   @brief Конструктор
	 @param diametre диаметр астероида
	 @param Speed скорость полета
	 @param screen размер окна
	 @param SpawnPosition позиция спавна
	 @param SpawnTime время, через которое астероид начнет полет
	 @param texture текстура астероида
	*/
	Asteroid(float diametre, float Speed, Vector2u screen, Vector2f SpawnPosition, int SpawnTime, Texture* texture);
	/**
	 @brief перемещение астероида на игрока
	 @param player игрок, на которого летит астероид
	*/
	void Move(Player& player);
	/**
	 @brief обновление позиции астероида
	 @param spawn новая точка спавна
	 @param texture начальная текстура
	*/
	void update(Vector2f spawn, Texture* texture);
	void setExist(bool e) { exist = e; clock.restart(); }
	bool& getExist() { return exist; }
	void setAsteroidMove(bool am) { asteroidIsMove = am; }
	bool& getAsteroidMove() { return asteroidIsMove; }
	int getKD() { return KD; }
	void setKD(float newKD) { KD = newKD; }
	/**
	 @brief анимация уничтожения астероида
	 @param textures текстуры взрыва
	*/
	void Destroy(std::vector<Texture*>& textures);
	void updateSpeed(float Speed);
private:
	float angleRotation;
	bool exist;
	bool flag = true;
	bool asteroidIsMove;
	Vector2f spawnPosition;
	Vector2f playerPos;
	float maxDistance;
};
#endif
