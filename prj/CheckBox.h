#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iosfwd>

using namespace sf;
///@brief класс кнопки с состояниями true / false
class CheckBox
{
public:
  Vector2f size;
  IntRect container;
  IntRect beginState;
  RectangleShape button;
  /**
   @brief Конструктор
   @param texture текстура, содержащая кнопку и ее состояния
   @param SizeRect размер прямоугольника кнопки на текстуре
   @param BeginRect прямоугольник начального состояния
   @param NextRect прямоугольник состояния при нажатии
   @param Size размер кнопки
   @param State начальное состояние (выбрано / не выбрано)
  */
  CheckBox(Texture* texture, Vector2f SizeRect, Vector2f BeginRect, Vector2f NextRect, Vector2f Size, bool State);
  /**
   @brief обрабатывает нажатие
   @param window окно игры
   @param sound звук нажатия
   @return нажата кнопка или нет
  */
  bool listen(RenderWindow& window, Sound& sound);
  /**
   @brief устанавивает позицию кнопку
   @param position новая позиция
  */
  void setPos(Vector2f position);
private:
  Clock clock;
  bool state;
  IntRect nextState;
  Vector2f beginRect;
  Vector2f sizeRect;
  Vector2f nextRect;
  /**
   @brief изменение параметров кнопки при нажатии
   @param window окно игры
   @param sound звук нажатия
   @return нажата кнопка или нет
  */
  void click();
};
#endif
