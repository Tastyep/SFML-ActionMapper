#include <memory>

#include <SFML/Window.hpp>

#include "ActionHandler.hpp"
#include "Manager.hpp"

#include "Actions.hpp"

class Window {
 public:
  Window()
    : _window(sf::VideoMode(800, 600), "InputConverter") {}

  void run() {
    sf::Event event;

    this->init();

    while (_window.isOpen()) {
      while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          this->close();
        }
      }
      _manager->run();
    }
  }

 private:
  void init() {
    using InputConverter::KeyCode;
    auto keyStateRecorder = std::make_unique<InputConverter::KeyStateRecorder>();
    auto keyMapper = std::make_unique<InputConverter::KeyMapper<Action>>();

    keyStateRecorder->observeKey(KeyCode::Escape);
    keyStateRecorder->observeKey(KeyCode::Up);
    keyMapper->map(KeyCode::Escape, Action::ESCAPE);
    keyMapper->map(KeyCode::Up, Action::UP);

    _manager = std::make_unique<InputConverter::Manager<Action>>(std::move(keyStateRecorder), std::move(keyMapper));

    _manager->dispatcher().registerHandler(Action::ESCAPE, std::make_shared<Handler>(*this));
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
  std::unique_ptr<InputConverter::Manager<Action>> _manager;
};

int main() {
  Window window;

  window.run();
  return 0;
}
