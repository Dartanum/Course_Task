#ifndef ROLLOVER_H
#define ROLLOVER_H

#include <SFML/Graphics.hpp>
#include <iosfwd>

using namespace sf;
///@brief регул€тор уровн€ громкости
class Rollover
{
public:
  int process;
  bool isPressed;
  float length;
  Text processText;
  RectangleShape line;
  RectangleShape slider;
  Vector2f position;
  float finishLineX;
  IntRect containerSlider;
  IntRect containerLine;
  /**
   @brief  онструктор
   @param textureLine текстура линии прогресса
   @param textureSlider текстура показател€ текущего прогресса
   @param rectSlider пр€моугольник текстуры, которую нужно обрезать
   @param sizeLine длина линии прогресса
   @param beginProcess текущий показатель прогресса
   @param font шрифт текста дл€ показа прогресса в процентах
   @param charSize размер букв текста
  */
  Rollover(Texture* textureLine, Texture* textureSlider, IntRect rectSlider, Vector2f sizeLine, int beginProcess, Font& font, int charSize);
  Rollover(Rollover&) = default;
  void setPos(Vector2f pos);
  /**
   @brief обрабатывает перемещение ползунка
   @param window окно игры
   @param event получаемое событие
  */
  void listen(RenderWindow& window, Event& event);

private:
  float setCurrentVolume(int volume);
  int getCurrentVolume(float currentPos);
  void updateContainer();
  void updateProcess();
};
#endif

