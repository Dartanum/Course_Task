#ifndef SETTINGS_H
#define SETTINGS_H
#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <fstream>
#include <sstream>

///@brief ��������� ����
class settings
{
public:
  /**
   @brief �����������
   @param Path ���� � ����� � �����������
   @param nickLength ������������ ����� ���� ������
  */
  settings(std::string& Path, int nickLength);
  settings() = default;
  settings(settings& set) = default;
  bool soundIsOn;
  bool musicIsOn;
  int soundVolume;
  int musicVolume;
  std::string nickname;
  int maxLengthNick;

  /**
   @brief ������ �� ����� � ��������� ������
   @return true ��� �������� �������� �����
  */
  bool read();
  /**
   @brief ������ � ���� �������� �� ���������� ������
   @return true ��� �������� �������� �����
  */
  bool write();
private:
  std::string path;
  /**
   @brief ������������ �������� �� ���������
  */
  void setDefault();
};
#endif

