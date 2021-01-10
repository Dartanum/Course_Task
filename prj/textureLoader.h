#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <iosfwd>
#include <iostream>

using namespace sf;
///@brief ��������� ��� ����������� ���������� ��������
enum Objects{
	PLAYER,
	PLANET,
	ASTEROID,
	WEAPON,
	DEST_EFFECT,
	UI,
	BACKGROUND
};
///@brief ��������� �������
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
	 @brief ��������� ���������� �������
	 @param obj ���������� �������
	 @param paths ���� � ������ �������
	*/
	void loader(enum Objects obj, std::vector<std::string>& paths);
	/**
   @brief ��������� ���������� ������� ��� ����
   @param textures ���� � ������ ������� � ����������
  */
	void loderMenu(std::map<std::string, std::string>& textures);
	/**
   @brief ��������� ��������
   @param obj ���������� ��������
   @param path ���� � ����� ��������
  */
	void loader(enum Objects obj, std::string& path);
	/**
   @brief ��������� �������� ��� ����
   @param path ���� � ����� ��������
   @param name �������� ��������
  */
	void loderMenu(std::string path, std::string name);
};
#endif
