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

///@brief ����� ��� ������������ ����
class Minimizer {
public:
  ///������� ���� ��� ���
  static bool isMinimize;
  ///���������� ����
  static WindowHandle handle;
  /**
  @brief ����� ������������ ���� ����
  @param window ������������� ����
  */
  static void minimizeWindow(RenderWindow& window);
};
///@brief ����� ������ ���� ���� ����
class Menu
{
public:
/**
@brief �����������
@param setting ��������� ����
@param records ������� ����
@param textures ��� ����������� ��������
@param ScreenSize ������ ����
@param font ����� ��� ����
@param recordFont ����� ��� ������� ��������
@param Prefix ������� ���� � ������
*/
  Menu(settings& setting, TopResults& records, textureLoader& textures, Vector2u& ScreenSize, Font& font, Font& recordFont, std::string Prefix);
/**
@brief ����� �������� ����
@param window ���� ����
@return ����� �� ���� ��� ���
*/
  bool menu(RenderWindow& window);
/**
@brief ����� ���� ���� ����� ����� ����
@param window ���� ����
@param pointsCount ���������� �����, ��������� �������
@param gameTime ����� � ��������, � ������� �������� ����� ��� ���
@param Background ��� ��� ����������� ���������
@return ����� ������� ������ � ������ ����
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
   @brief ����� ������� � ���������
   @param window ���� ����
  */
  void Rules(RenderWindow& window);
  /**
   @brief ����� ������� � �����������
   @param window ���� ����
  */
  void Settings(RenderWindow& window);
  /**
   @brief ����� ������� � �������� ��������
   @param window ���� ����
  */
  void Records(RenderWindow& window);
  /**
   @brief ��������������� �������� ����
  */
  void buildMainMenu();
  /**
   @brief ���� ������ � ����������
   @param window ���� ����
   @param event ���������� �������
   @param text ���������� �����
   @return true, ���� ���������� ���������
  */
  bool enterText(RenderWindow& window, Event& event, Text& text);
  IntRect buildNickArea(Text& text);
  std::vector<Vector2f> chooseStateCheckbox(bool isSound);
};
#endif

