#ifndef TOPRESULTS_H
#define TOPRESULTS_H

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

///@brief рекорд
struct Result
{
  bool operator==(const Result rhs) const;
  bool operator!=(const Result rhs) const { return !operator==(rhs); }
  std::string name;
  int points = 0;
  int time = 0;
};
///@brief топ рекордов
class TopResults
{
public:
  /**
   @brief  онструктор
   @param Path путь к файлу с рекордами
   @param SizeTop количество записей в топе
  */
  TopResults(std::string& Path, int SizeTop);
  TopResults() = default;
  TopResults(TopResults&) = default;

  std::vector<Result> top;
  sf::Text text;
  /**
   @brief чтение из файла с рекордами и запись в экземпл€р класса
   @return true при успешном открытии файла
  */
  bool read();
  /**
   @param перезаписывание файла с рекордами данными из экземпл€ра класса
   @return true при успешном открытии файла
  */
  bool write();
  /**
   @brief запись нового рекорда в экземпл€р класса с сортировкой и перезаписью в файл
   @param name им€ игрока
   @param point количество набранных очков
   @param time врем€ бо€
   @return true при успешном открытии файла
  */
  bool write(std::string name, int point, int time);
  /**
   @brief проверка входит ли введенное количество очков в таблицу рекордов
   @param point количество очков
   @return true, если рекорд входит в таблицу
  */
  bool isRecord(int point);
  /**
   @brief создание макета таблицы рекордов
   @param charSize размер символов
   @param font шрифт текста
   @param color цвет текста
  */
  void makeView(int charSize, sf::Font& font, sf::Color color);
private:
  std::string makeSpace(int count);
  std::string path;
  Result defaultResult;
  int sizeTop;
};
#endif
