#ifndef PLAYER_H
#define PLAYER_H
#define PI 3.14159265

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>
#include <cmath>

using namespace sf;
///@brief ����� ������
class Player {
public:
	Clock dest_anim_clock;
	RectangleShape dest;
	bool anim_end;
	Vector2f pos_die;
	RectangleShape player;

	Player() = default;
	/**
	 @brief �����������
	 @param texture �������� ������, ���������� ��� ��� ���������
	 @param speed �������� ��������
	 @param angularSpeed �������� ��������
	 @param screen ������ ����
	*/
	Player(Texture* texture, const double& speed, const double& angularSpeed, Vector2u screen);
	Player(const Player&) = default;

	/**
	 @brief ����� �������� ��� �������� ������
	 @param time ����� ����
	 @param currentFrame ������� ����
	*/
	void flyForward(float time, float& currentFrame);
	///@brief ��������� ��� �������� �����
	void flyBack(const float& time); 
	///@brief ������� ����� �� �����
	void flyLeft(const float& time); 
	///@brief ������� ������ �� �����
	void flyRight(const float& time); 
	/**
	 @brief ������������ ������
	 @param forward true, ���� ����� �������� ������
	*/
	void Move(bool forward); 
	///@brief ������������� ������� ������ � �����
	void flyForwardAndBack(); 
	///@brief ������������ ������������ ��������� ������� (��� �������)
	void standartCondition();
	Vector2f getPos();
	/**
	 @brief �������� ������
	 @param textures �������� ������
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