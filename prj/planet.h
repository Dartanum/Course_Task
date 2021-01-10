#ifndef PLANET_H
#define PLANET_H
#include <SFML/Graphics.hpp>
#include <iosfwd>

using namespace sf;

///@brief класс планеты
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
	 @brief Конструктор
	 @param Radius радиус планеты
	 @param AngularSpeed скорость вращения
	 @param texture текстура планеты
	 @param Position позиция спавна 
	 @param hp_ количество очков прочности
	 @param spawnKD_ время следующего появления
	 @param Area номер занимаемой области на экране
	 @param font шрифт текста количества очков прочности
	 @param icon_ иконка щита слева от очков прочности
	 @param dest_effect текстура, содержащая состояния взрыва планеты
	*/
	Planet(float Radius, float AngularSpeed, Texture* texture, Vector2f Position, int hp_, float spawnKD_, int Area, Font& font, Texture* icon_, Texture* dest_effect);
	/**
	 @brief столкновение объекта с планетой
	 @param shape объект, над которым проводится проверка на столкновение
	 @return true, если произошло столкновение, иначе false
	*/
	bool Intersects(RectangleShape shape);
	/**
	 @brief поворот планеты вокруг своей оси
	*/
	void Rotation();
	/**
	 @brief анимация рождения планеты
	*/
	void Spawn();
	/**
	 @brief обновление параметров планеты после ее смерти
	 @param Radius новый радиус
	 @param AngularSpeed новая скорость вращения вокруг своей оси
	 @param texture новая текстура планеты
	 @param Position новая позиция спавна
	 @param hp_ новое количество очков прочности
	 @param spawnKD_ новое время следующего появления
	 @param area новая занимаемая область экрана
	*/
	void Die(float Radius, float AngularSpeed, Texture* texture, Vector2f Position, int hp_, float spawnKD_, int area);
	/**
	 @brief анимация уничтожения планеты на одной текстуре
	 @param width ширина текстуры
	 @param height высота текстуры
	 @param beginPoint начальная точка обрезания прямоугольника
	 @param sizeRect размер прямоугольника
	*/
	void Destroy(int width, int height, Vector2f beginPoint, int sizeRect);
	/**
	 @brief установление полупрозрачности при столкновении с объектом
	 @param object объект, на столкновение с которым идет проверка
	*/
	void Transparency(RectangleShape& object);
	/**
	 @brief проверка и обработка смерти планеты
	 @param gameTime время, в которое планета умерла
	 @return true, если планета уничтожена, иначе false
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