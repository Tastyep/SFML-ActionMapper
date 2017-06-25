#include <SFML/Window.hpp>

#include "KeyStateRecorder.hpp"

#include <iostream>

int main() {
  sf::Window window(sf::VideoMode(800, 600), "ActionMapper");
  sf::Event event;
  ActionMapper::KeyStateRecorder keyStateRecorder;

  keyStateRecorder.observeKey(ActionMapper::KeyCode::Escape);

  while (window.isOpen()) {
    keyStateRecorder.checkKeys();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    const auto pressedKeys = keyStateRecorder.pressedKeys();

    for (auto keyCode : pressedKeys) {
      std::cout << "key Pressed: " << (int)keyCode << std::endl;
    }
  }
  return 0;
}
