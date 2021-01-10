#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iosfwd>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "settings.h"
#include "MenuButton.h"
#include "CheckBox.h"
#include "Rollover.h"
#include "textureLoader.h"
#include "TopResults.h"

using namespace sf;

///@brief класс для сворачивания окна
class Minimizer {
public:
  ///свёрнуто окно или нет
  static bool isMinimize;
  ///дескриптор окна
  static WindowHandle handle;
  /**
  @brief метод сворачивания окна игры
  @param window сворачиваемое окно
  */
  static void minimizeWindow(RenderWindow& window);
};
///@brief класс вызова всех меню игры
class Menu
{
public:
/**
@brief Конструктор
@param setting настройки игры
@param records рекорды игры
@param textures все загруженные текстуры
@param ScreenSize размер окна
@param font шрифт для меню
@param recordFont шрифт для таблицы рекордов
@param Prefix префикс пути к файлам
*/
  Menu(settings& setting, TopResults& records, textureLoader& textures, Vector2u& ScreenSize, Font& font, Font& recordFont, std::string Prefix);
/**
@brief вызов главного меню
@param window окно игры
@return выйти из игры или нет
*/
  bool menu(RenderWindow& window);
/**
@brief вызов меню меню после конца игры
@param window окно игры
@param pointsCount количество очков, набранных игроком
@param gameTime время в секундах, в течении которого игрок был жив
@param Background фон для продолжения рисования
@return номер нажатой кнопки в данном меню
*/
  int endGameMenu(RenderWindow& window, int pointsCount, int gameTime, RectangleShape& Background);
private:
  Clock clock;
  std::string prefix;
  float delayFrame;
  std::string rules;
  SoundBuffer clickBuffer;
  SoundBuffer rolloverBuffer;
  Texture* textures;
  Texture* sliderTexture;
  RectangleShape background;
  RectangleShape logo;
  Vector2u screenSize;
  float screenR;
  Vector2f buttonSize;
  Font font;
  Font topFont;
  std::vector<MenuButton> buttons;
  RectangleShape back;
  settings settings_;
  TopResults top;

  /**
   @brief показ вкладки с правилами
   @param window окно игры
  */
  void Rules(RenderWindow& window);
  /**
   @brief показ вкладки с настройками
   @param window окно игры
  */
  void Settings(RenderWindow& window);
  /**
   @brief показ вкладки с таблицей рекордов
   @param window окно игры
  */
  void Records(RenderWindow& window);
  /**
   @brief конструирование главного меню
  */
  void buildMainMenu();
  /**
   @brief ввод текста с клавиатуры
   @param window окно игры
   @param event получаемое событие
   @param text изменяемый текст
   @return true, если происходит изменение
  */
  bool enterText(RenderWindow& window, Event& event, Text& text);
  IntRect buildNickArea(Text& text);
  std::vector<Vector2f> chooseStateCheckbox(bool isSound);
};
#endif

