#ifndef ASTEROID_H
#define ASTEROID_H
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <math.h>

#include "player.h"
#include "textureLoader.h"

using namespace sf;
///@brief ����� ����������
class Asteroid {
public:
	///������� ���������
	float diametre;
	///�������� ������ ���������
	float speed;
	///����� � ��������, ����� ������� �������� ��������
	float KD;
	///����� ������� ��������� � ��������
	int spawnTime;
	///������, �� ������� ������������� �������� ������
	Sprite dest_sprite;
	///������ ���������
	RectangleShape asteroid;
	Clock clock;
	///������ ��� �������� �����������
	Clock dest_anim_clock;
	///�������, �� ������� �������� ��� ���������
	Vector2f dest_pos;
	///��������� �������� ��� ���
	bool destroy;

	Asteroid() = default;
	Asteroid(Asteroid&) = default;
	/**
   @brief �����������
	 @param diametre ������� ���������
	 @param Speed �������� ������
	 @param screen ������ ����
	 @param SpawnPosition ������� ������
	 @param SpawnTime �����, ����� ������� �������� ������ �����
	 @param texture �������� ���������
	*/
	Asteroid(float diametre, float Speed, Vector2u screen, Vector2f SpawnPosition, int SpawnTime, Texture* texture);
	/**
	 @brief ����������� ��������� �� ������
	 @param player �����, �� �������� ����� ��������
	*/
	void Move(Player& player);
	/**
	 @brief ���������� ������� ���������
	 @param spawn ����� ����� ������
	 @param texture ��������� ��������
	*/
	void update(Vector2f spawn, Texture* texture);
	void setExist(bool e) { exist = e; clock.restart(); }
	bool& getExist() { return exist; }
	void setAsteroidMove(bool am) { asteroidIsMove = am; }
	bool& getAsteroidMove() { return asteroidIsMove; }
	int getKD() { return KD; }
	void setKD(float newKD) { KD = newKD; }
	/**
	 @brief �������� ����������� ���������
	 @param textures �������� ������
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
