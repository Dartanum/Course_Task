#ifndef SETTINGS_H
#define SETTINGS_H
#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <fstream>
#include <sstream>

///@brief настройки игры
class settings
{
public:
  /**
   @brief  онструктор
   @param Path путь к файлу с настройками
   @param nickLength максимальна€ длина ника игрока
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
   @brief чтение из файла в экземпл€р класса
   @return true при успешном открытии файла
  */
  bool read();
  /**
   @brief запись в файл настроек из экземпл€ра класса
   @return true при успешном открытии файла
  */
  bool write();
private:
  std::string path;
  /**
   @brief установление настроек по умолчанию
  */
  void setDefault();
};
#endif

