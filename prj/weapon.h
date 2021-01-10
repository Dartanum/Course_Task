#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Graphics.hpp>
#include <cmath>

#include "player.h"

using namespace sf;
///@brief ������ ������
class Weapon
{
public: 
	RectangleShape weapon;
	Clock clock;
	Weapon() = default;
	Weapon(Weapon&) = default;
	/**
	 @brief �����������
	 @param texture �������� ������
	 @param Speed �������� ������
	 @param kd ����� �����������
	 @param screenR ����������� ������ � ������ ������
	*/
	Weapon(Texture* texture, double Speed, float kd, float screenR);
	/**
	 @brief ����������� ������
	 @param player �����, ������� ���������� �������
	*/
	void Move(Player& player);
	/**
	 @brief �������� ������� �� ������� ����
	*/
	void update();
	bool getIsMove() { return weaponIsMove; }
	void setIsMove(bool newMove) { weaponIsMove = newMove; }
	float getKD() { return KD; }
private:
	bool flag = true;
	float KD;
	double speed;
	bool weaponIsMove;
	Vector2f spawnPosition;
};
#endif

