#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Graphics.hpp>
#include <cmath>

#include "player.h"

using namespace sf;
///@brief оружие игрока
class Weapon
{
public: 
	RectangleShape weapon;
	Clock clock;
	Weapon() = default;
	Weapon(Weapon&) = default;
	/**
	 @brief Конструктор
	 @param texture текстура лазера
	 @param Speed скорость полета
	 @param kd время перезарядки
	 @param screenR соотношение ширины и высоты экрана
	*/
	Weapon(Texture* texture, double Speed, float kd, float screenR);
	/**
	 @brief перемещение лазера
	 @param player игрок, который производит выстрел
	*/
	void Move(Player& player);
	/**
	 @brief удаление снаряда из игровой зоны
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

