#include "MenuButton.h"

MenuButton::MenuButton(Texture* texture_, Vector2f textureRectSize, Vector2f beginPosTexture, Vector2f NextRect, Vector2f size_, std::string name_, Font& font) {
  size = size_;
  button.setSize(size);
  nextRect = NextRect;
  button.setTexture(texture_);
  button.setOrigin(size.x / 2, size.y / 2);
  beginRect = beginPosTexture;
  sizeRect = textureRectSize;
  name = name_;
  text.setFont(font);
  text.setString(name);
  text.setCharacterSize(size.y / 2);
  text.setOrigin(Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
  button.setTextureRect(IntRect(beginRect.x, beginRect.y, sizeRect.x, sizeRect.y));
  isClick = false;
  choose = false;
}

void MenuButton::setPos(MenuButton& buttonAbove, int interval) {
  button.setPosition(buttonAbove.button.getPosition().x, buttonAbove.button.getPosition().y + size.y + interval);
  text.setPosition(button.getPosition().x, button.getPosition().y - interval / 2);
  container = IntRect(button.getPosition().x - size.x / 2, button.getPosition().y - size.y / 2, size.x, size.y);
}

void MenuButton::setPos(RectangleShape& back, int interval) {
  button.setPosition(back.getPosition().x, back.getPosition().y - back.getSize().y / 2 + interval + size.y / 2);
  text.setPosition(button.getPosition().x, button.getPosition().y - interval/2);
  container = IntRect(button.getPosition().x - size.x / 2, button.getPosition().y - size.y / 2, size.x, size.y);
}

void MenuButton::setPos(Vector2f position) {
  button.setPosition(position);
  text.setPosition(button.getPosition().x, button.getPosition().y - 5);
  container = IntRect(button.getPosition().x - size.x / 2, button.getPosition().y - size.y / 2, size.x, size.y);
}

void MenuButton::setSizeRelativeText() {
  button.setSize(Vector2f(text.getGlobalBounds().width + 40, text.getGlobalBounds().height + 20));
  button.setOrigin(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2);
  size = button.getSize();
  container = IntRect(button.getPosition().x - size.x / 2, button.getPosition().y - size.y / 2, size.x, size.y);
}

void MenuButton::standart() {
  isClick = false;
  button.setFillColor(Color::White);
  button.setTextureRect(IntRect(beginRect.x, beginRect.y, sizeRect.x, sizeRect.y));
}

void MenuButton::click() {
  isClick = true;
  button.setTextureRect(IntRect(nextRect.x, nextRect.y, sizeRect.x, sizeRect.y-5));
}

bool MenuButton::listen(RenderWindow& window, Sound& soundClick, Sound& soundRoll) {
  bool abroad = true;
  int currentFrame = clock.getElapsedTime().asMilliseconds() / 16;

  if (isClick) isClick = !isClick;
  if (container.contains(Mouse::getPosition(window))) {
    abroad = false;
  }
  else standart();
  if (abroad) choose = false;
  if (container.contains(Mouse::getPosition(window))) {
    if (choose == false) soundRoll.play();
    button.setFillColor(Color::Green);
    choose = true;
  }
  else {
    button.setFillColor(Color::White);
    choose = false;
  }
  if (currentFrame > 20) button.setTextureRect(IntRect(beginRect.x, beginRect.y, sizeRect.x, sizeRect.y));
  if (Mouse::isButtonPressed(Mouse::Left) && choose && currentFrame > 20) {
    click();
    soundClick.play();
    clock.restart();
  }
  return isClick;
}