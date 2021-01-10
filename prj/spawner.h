#ifndef SPAWNER_H
#define SPAWNER_H

#include <random>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
///@brief генератор параметров для объектов
class Spawner
{
  std::random_device rd;
public:
  /**
   @brief создает точку спавна астероида в допустимых зонах
   @param screen размер окна
   @return позиция спавна астероида
  */
  Vector2f generatorAsteroids(Vector2u screen);
  /**
   @brief создает точку спавна планеты в заданной области
   @param screen размер окна
   @param spawnPoints массив позиций левых верхних углов областей спавна
   @param radius радиус планеты
   @param area выбранная область спавна
   @return координаты спавна планеты
  */
  Vector2f generatorPlanets(Vector2u screen, std::vector<Vector2f>& spawnPoints, int radius, int& area);
  /**
   @brief выбор области спавна
   @param spawnPoints массив позиций левых верхних углов областей спавна
   @param useSpawnPoints координаты верхних левых углов областей спавна, которые заняты в данный момент
   @return номер области спавна
  */
  int chooseArea(std::vector<Vector2f>& spawnPoints, std::map<int, Vector2f>& useSpawnPoints);
  /**
   @brief генератор случайного int числа
   @param min минимальное генерируемое число
   @param max максимальное генерируемое число
   @return случайное число
  */
  int generator(int min, int max);
  /**
   @brief генератор случайного float числа
   @param min минимальное генерируемое число
   @param max максимальное генерируемое число
   @return случайное число
  */
  float generator(float min, float max);
};
#endif