#ifndef PLAYER_H
#define PLAYER_H
#define PI 3.14159265

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>
#include <cmath>

using namespace sf;
///@brief класс игрока
class Player {
public:
	Clock dest_anim_clock;
	RectangleShape dest;
	bool anim_end;
	Vector2f pos_die;
	RectangleShape player;

	Player() = default;
	/**
	 @brief Конструктор
	 @param texture текстура игрока, содержащая все его состояния
	 @param speed скорость движения
	 @param angularSpeed скорость поворота
	 @param screen размер окна
	*/
	Player(Texture* texture, const double& speed, const double& angularSpeed, Vector2u screen);
	Player(const Player&) = default;

	/**
	 @brief смена анимации при движении вперед
	 @param time время игры
	 @param currentFrame текущий кадр
	*/
	void flyForward(float time, float& currentFrame);
	///@brief остановка при движении назад
	void flyBack(const float& time); 
	///@brief поворот влево на месте
	void flyLeft(const float& time); 
	///@brief поворот вправо на месте
	void flyRight(const float& time); 
	/**
	 @brief передвижение игрока
	 @param forward true, если игрок движется вперед
	*/
	void Move(bool forward); 
	///@brief одновременное нажатие вперед и назад
	void flyForwardAndBack(); 
	///@brief установление стандартного состояния корабля (без пламяни)
	void standartCondition();
	Vector2f getPos();
	/**
	 @brief анимация взрыва
	 @param textures текстуры взрыва
	*/
	void Destroy(std::vector<Texture*>& textures);

private:
	double speed; 
	float time; 
	double angularSpeed; 
	int width; 
	int heigth; 
	Vector2u screen; 
};
#endif