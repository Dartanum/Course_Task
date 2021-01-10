#ifndef ROLLOVER_H
#define ROLLOVER_H

#include <SFML/Graphics.hpp>
#include <iosfwd>

using namespace sf;
///@brief ��������� ������ ���������
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
   @brief �����������
   @param textureLine �������� ����� ���������
   @param textureSlider �������� ���������� �������� ���������
   @param rectSlider ������������� ��������, ������� ����� ��������
   @param sizeLine ����� ����� ���������
   @param beginProcess ������� ���������� ���������
   @param font ����� ������ ��� ������ ��������� � ���������
   @param charSize ������ ���� ������
  */
  Rollover(Texture* textureLine, Texture* textureSlider, IntRect rectSlider, Vector2f sizeLine, int beginProcess, Font& font, int charSize);
  Rollover(Rollover&) = default;
  void setPos(Vector2f pos);
  /**
   @brief ������������ ����������� ��������
   @param window ���� ����
   @param event ���������� �������
  */
  void listen(RenderWindow& window, Event& event);

private:
  float setCurrentVolume(int volume);
  int getCurrentVolume(float currentPos);
  void updateContainer();
  void updateProcess();
};
#endif

