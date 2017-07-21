#include <memory>

#include <SFML/Window.hpp>

#include "ActionHandler.hpp"
#include "Manager.hpp"

#include "Actions.hpp"

class Window {
 public:
  Window()
    : _window(sf::VideoMode(800, 600), "InputConverter") {
    _window.setFramerateLimit(30);
  }

  void run() {
    sf::Event event;

    this->init();

    while (_window.isOpen()) {
      while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          this->close();
        }
      }
      _manager.run();
      _window.display();
    }
  }

 private:
  void init() {
    using Key = sf::Keyboard::Key;

    _manager.bind(Key::Escape, Action::ESCAPE);
    _manager.bind(Key::Up, Action::UP);

    _manager.dispatcher()->registerHandler(Action::ESCAPE, std::make_shared<Handler>(*this));
  }

  void close() {
    _window.close();
  }

 private:
  struct Handler : public InputConverter::ActionHandler<Action> {
    Handler(Window& window)
      : _window(window) {}

    void handle(Action) override {
      _window.close();
    }

   private:
    Window& _window;
  };

 private:
  sf::Window _window;
  InputConverter::Manager<Action> _manager;
};

int main() {
  Window window;

  window.run();
  return 0;
}
