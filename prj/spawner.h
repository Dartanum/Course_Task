#ifndef SPAWNER_H
#define SPAWNER_H

#include <random>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
///@brief ��������� ���������� ��� ��������
class Spawner
{
  std::random_device rd;
public:
  /**
   @brief ������� ����� ������ ��������� � ���������� �����
   @param screen ������ ����
   @return ������� ������ ���������
  */
  Vector2f generatorAsteroids(Vector2u screen);
  /**
   @brief ������� ����� ������ ������� � �������� �������
   @param screen ������ ����
   @param spawnPoints ������ ������� ����� ������� ����� �������� ������
   @param radius ������ �������
   @param area ��������� ������� ������
   @return ���������� ������ �������
  */
  Vector2f generatorPlanets(Vector2u screen, std::vector<Vector2f>& spawnPoints, int radius, int& area);
  /**
   @brief ����� ������� ������
   @param spawnPoints ������ ������� ����� ������� ����� �������� ������
   @param useSpawnPoints ���������� ������� ����� ����� �������� ������, ������� ������ � ������ ������
   @return ����� ������� ������
  */
  int chooseArea(std::vector<Vector2f>& spawnPoints, std::map<int, Vector2f>& useSpawnPoints);
  /**
   @brief ��������� ���������� int �����
   @param min ����������� ������������ �����
   @param max ������������ ������������ �����
   @return ��������� �����
  */
  int generator(int min, int max);
  /**
   @brief ��������� ���������� float �����
   @param min ����������� ������������ �����
   @param max ������������ ������������ �����
   @return ��������� �����
  */
  float generator(float min, float max);
};
#endif