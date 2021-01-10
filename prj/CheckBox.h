#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iosfwd>

using namespace sf;
///@brief ����� ������ � ����������� true / false
class CheckBox
{
public:
  Vector2f size;
  IntRect container;
  IntRect beginState;
  RectangleShape button;
  /**
   @brief �����������
   @param texture ��������, ���������� ������ � �� ���������
   @param SizeRect ������ �������������� ������ �� ��������
   @param BeginRect ������������� ���������� ���������
   @param NextRect ������������� ��������� ��� �������
   @param Size ������ ������
   @param State ��������� ��������� (������� / �� �������)
  */
  CheckBox(Texture* texture, Vector2f SizeRect, Vector2f BeginRect, Vector2f NextRect, Vector2f Size, bool State);
  /**
   @brief ������������ �������
   @param window ���� ����
   @param sound ���� �������
   @return ������ ������ ��� ���
  */
  bool listen(RenderWindow& window, Sound& sound);
  /**
   @brief ������������ ������� ������
   @param position ����� �������
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
   @brief ��������� ���������� ������ ��� �������
   @param window ���� ����
   @param sound ���� �������
   @return ������ ������ ��� ���
  */
  void click();
};
#endif
