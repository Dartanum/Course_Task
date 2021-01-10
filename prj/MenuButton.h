#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iosfwd>

using namespace sf;
///@brief классичесая кнопка
class MenuButton
{
public:
  ///текст на кнопке
  Text text;
  ///объект кнопки
  RectangleShape button;
  ///размер кнопки
  Vector2f size;
  /**
   @brief Конструктор
   @param texture_ текстура кнопки с несколькими состояниями
   @param textureRectSize размер прямоугольника кнопки на текстуре
   @param beginPosTexture позиция левого верхнего угла прямоугольника кнопки на текстуре
   @param NextRect позиция левого верхнего угла прямоугольника кнопки на текстуре при нажатии
   @param size размер кнопки
   @param name_ выводимый текст
   @param font шрифт текста
  */
  MenuButton(Texture* texture_, Vector2f textureRectSize, Vector2f beginPosTexture, Vector2f NextRect, Vector2f size, std::string name_, Font& font);
  /**
   @brief установка позиции кнопки относительно кнопки сверху
   @param buttonAbove кнопка, относительно которой устанавливается позиция
   @param interval расстояние между кнопками
  */
  void setPos(MenuButton& buttonAbove, int interval);
  /**
   @brief установка позиции кнопки относительно верхней границы заднего фона на расстоянии
   @param back фон за кнопкой
   @param interval расстояние отступа кнопки от верхней границы фона
  */
  void setPos(RectangleShape& back, int interval);
  /**
   @brief установка позиции кнопки
   @param position новая позиция
  */
  void setPos(Vector2f position);
  /**
   @brief установление размера кнопки относительно размера текста в ней
  */
  void setSizeRelativeText();
  /**
   @brief обрабатывает нажатие
   @param window окно игры
   @param soundClick звук нажатия
   @param soundRoll звук наведения мыши на кнопку
   @return нажата кнопка или нет
  */
  bool listen(RenderWindow& window, Sound& soundClick, Sound& soundRoll);
private:
  std::string name;
  bool isClick;
  Vector2f beginRect;
  Vector2f sizeRect;
  Vector2f nextRect;
  IntRect container;
  Clock clock;
  bool choose;
  /**
   @brief установление стандартного состояния кнопки
  */
  void standart();
  /**
   @brief установление состояния кнопки при нажатии
  */
  void click();
};
#endif

