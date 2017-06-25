#include <SFML/Window.hpp>

#include "Actions.hpp"
#include "KeyMapper.hpp"
#include "KeyStateRecorder.hpp"

#include <iostream>

int main() {
  sf::Window window(sf::VideoMode(800, 600), "InputConverter");
  sf::Event event;

  InputConverter::KeyStateRecorder keyStateRecorder;
  InputConverter::KeyMapper keyMapper;

  keyStateRecorder.observeKey(InputConverter::KeyCode::Escape);
  keyMapper.map<InputConverter::Type<InputConverter::Action::ESCAPE>>(InputConverter::KeyCode::Escape);

  while (window.isOpen()) {
    keyStateRecorder.checkKeys();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    const auto pressedKeys = keyStateRecorder.pressedKeys();

    for (auto keyCode : pressedKeys) {
      auto hash = keyMapper[keyCode];
      std::cout << "key Pressed: " << (int)keyCode << " hash: " << hash << std::endl;
    }
  }
  return 0;
}
