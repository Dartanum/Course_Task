#ifndef PLANET_H
#define PLANET_H
#include <SFML/Graphics.hpp>
#include <iosfwd>

using namespace sf;

///@brief ����� �������
class Planet {
public:
	Clock spawnClock;
	CircleShape planet;
	RectangleShape icon;
	Texture texture_planet;
	Texture dest_effect_planet;
	Text hpView;
	int occupiedArea;
	int hp;
	int currentHp;
	bool born;
	float spawnKD;
	int deathTime;
	bool beginSpawn;
	bool destroy;
	bool beginDestroy;

	Planet() = default;
	Planet(const Planet&) = default;
	/**
	 @brief �����������
	 @param Radius ������ �������
	 @param AngularSpeed �������� ��������
	 @param texture �������� �������
	 @param Position ������� ������ 
	 @param hp_ ���������� ����� ���������
	 @param spawnKD_ ����� ���������� ���������
	 @param Area ����� ���������� ������� �� ������
	 @param font ����� ������ ���������� ����� ���������
	 @param icon_ ������ ���� ����� �� ����� ���������
	 @param dest_effect ��������, ���������� ��������� ������ �������
	*/
	Planet(float Radius, float AngularSpeed, Texture* texture, Vector2f Position, int hp_, float spawnKD_, int Area, Font& font, Texture* icon_, Texture* dest_effect);
	/**
	 @brief ������������ ������� � ��������
	 @param shape ������, ��� ������� ���������� �������� �� ������������
	 @return true, ���� ��������� ������������, ����� false
	*/
	bool Intersects(RectangleShape shape);
	/**
	 @brief ������� ������� ������ ����� ���
	*/
	void Rotation();
	/**
	 @brief �������� �������� �������
	*/
	void Spawn();
	/**
	 @brief ���������� ���������� ������� ����� �� ������
	 @param Radius ����� ������
	 @param AngularSpeed ����� �������� �������� ������ ����� ���
	 @param texture ����� �������� �������
	 @param Position ����� ������� ������
	 @param hp_ ����� ���������� ����� ���������
	 @param spawnKD_ ����� ����� ���������� ���������
	 @param area ����� ���������� ������� ������
	*/
	void Die(float Radius, float AngularSpeed, Texture* texture, Vector2f Position, int hp_, float spawnKD_, int area);
	/**
	 @brief �������� ����������� ������� �� ����� ��������
	 @param width ������ ��������
	 @param height ������ ��������
	 @param beginPoint ��������� ����� ��������� ��������������
	 @param sizeRect ������ ��������������
	*/
	void Destroy(int width, int height, Vector2f beginPoint, int sizeRect);
	/**
	 @brief ������������ ���������������� ��� ������������ � ��������
	 @param object ������, �� ������������ � ������� ���� ��������
	*/
	void Transparency(RectangleShape& object);
	/**
	 @brief �������� � ��������� ������ �������
	 @param gameTime �����, � ������� ������� ������
	 @return true, ���� ������� ����������, ����� false
	*/
	bool DestroyListener(int gameTime);
private:
	Font font;
	Clock dest_anim_clock;
	float radius;
	float angularSpeed;
	Vector2f position;

};
#endif