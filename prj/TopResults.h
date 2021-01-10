#ifndef TOPRESULTS_H
#define TOPRESULTS_H

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

///@brief ������
struct Result
{
  bool operator==(const Result rhs) const;
  bool operator!=(const Result rhs) const { return !operator==(rhs); }
  std::string name;
  int points = 0;
  int time = 0;
};
///@brief ��� ��������
class TopResults
{
public:
  /**
   @brief �����������
   @param Path ���� � ����� � ���������
   @param SizeTop ���������� ������� � ����
  */
  TopResults(std::string& Path, int SizeTop);
  TopResults() = default;
  TopResults(TopResults&) = default;

  std::vector<Result> top;
  sf::Text text;
  /**
   @brief ������ �� ����� � ��������� � ������ � ��������� ������
   @return true ��� �������� �������� �����
  */
  bool read();
  /**
   @param ��������������� ����� � ��������� ������� �� ���������� ������
   @return true ��� �������� �������� �����
  */
  bool write();
  /**
   @brief ������ ������ ������� � ��������� ������ � ����������� � ����������� � ����
   @param name ��� ������
   @param point ���������� ��������� �����
   @param time ����� ���
   @return true ��� �������� �������� �����
  */
  bool write(std::string name, int point, int time);
  /**
   @brief �������� ������ �� ��������� ���������� ����� � ������� ��������
   @param point ���������� �����
   @return true, ���� ������ ������ � �������
  */
  bool isRecord(int point);
  /**
   @brief �������� ������ ������� ��������
   @param charSize ������ ��������
   @param font ����� ������
   @param color ���� ������
  */
  void makeView(int charSize, sf::Font& font, sf::Color color);
private:
  std::string makeSpace(int count);
  std::string path;
  Result defaultResult;
  int sizeTop;
};
#endif
