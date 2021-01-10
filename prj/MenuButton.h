#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iosfwd>

using namespace sf;
///@brief ����������� ������
class MenuButton
{
public:
  ///����� �� ������
  Text text;
  ///������ ������
  RectangleShape button;
  ///������ ������
  Vector2f size;
  /**
   @brief �����������
   @param texture_ �������� ������ � ����������� �����������
   @param textureRectSize ������ �������������� ������ �� ��������
   @param beginPosTexture ������� ������ �������� ���� �������������� ������ �� ��������
   @param NextRect ������� ������ �������� ���� �������������� ������ �� �������� ��� �������
   @param size ������ ������
   @param name_ ��������� �����
   @param font ����� ������
  */
  MenuButton(Texture* texture_, Vector2f textureRectSize, Vector2f beginPosTexture, Vector2f NextRect, Vector2f size, std::string name_, Font& font);
  /**
   @brief ��������� ������� ������ ������������ ������ ������
   @param buttonAbove ������, ������������ ������� ��������������� �������
   @param interval ���������� ����� ��������
  */
  void setPos(MenuButton& buttonAbove, int interval);
  /**
   @brief ��������� ������� ������ ������������ ������� ������� ������� ���� �� ����������
   @param back ��� �� �������
   @param interval ���������� ������� ������ �� ������� ������� ����
  */
  void setPos(RectangleShape& back, int interval);
  /**
   @brief ��������� ������� ������
   @param position ����� �������
  */
  void setPos(Vector2f position);
  /**
   @brief ������������ ������� ������ ������������ ������� ������ � ���
  */
  void setSizeRelativeText();
  /**
   @brief ������������ �������
   @param window ���� ����
   @param soundClick ���� �������
   @param soundRoll ���� ��������� ���� �� ������
   @return ������ ������ ��� ���
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
   @brief ������������ ������������ ��������� ������
  */
  void standart();
  /**
   @brief ������������ ��������� ������ ��� �������
  */
  void click();
};
#endif

