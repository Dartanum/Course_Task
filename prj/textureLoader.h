#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>

using namespace sf;
///@brief константы для определения назначения текстуры
enum Objects{
	PLAYER,
	PLANET,
	ASTEROID,
	WEAPON,
	DEST_EFFECT,
	UI,
	BACKGROUND
};
///@brief хранилище текстур
class textureLoader
{
public:
	std::vector<Texture*> players;
	std::vector<Texture*> planets;
	std::vector<Texture*> asteroids;
	std::vector<Texture*> weapons;
	std::vector<Texture*> dest_effect;
	std::vector<Texture*> ui;
	std::vector<Texture*> backgrounds;
	std::map<std::string, sf::Texture*> menu;

	textureLoader() = default;
	textureLoader(textureLoader&) = default;
	/**
	 @brief загрузчик нескольких текстур
	 @param obj назначение текстур
	 @param paths пути к файлам текстур
	*/
	void loader(enum Objects obj, std::vector<std::string>& paths);
	/**
   @brief загрузчик нескольких текстур для меню
   @param textures пути к файлам текстур с названиями
  */
	void loderMenu(std::map<std::string, std::string>& textures);
	/**
   @brief загрузчик текстуры
   @param obj назначение текстуры
   @param path путь к файлу текстуры
  */
	void loader(enum Objects obj, std::string& path);
	/**
   @brief загрузчик текстуры для меню
   @param path путь к файлу текстуры
   @param name название текстуры
  */
	void loderMenu(std::string path, std::string name);
};
#endif
