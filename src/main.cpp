#include <memory>

#include <SFML/Window.hpp>

#include "ActionHandler.hpp"
#include "KeyMapper.hpp"
#include "KeyStateRecorder.hpp"
#include "Manager.hpp"

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
    using InputConverter::Action;
    auto keyStateRecorder = std::make_unique<InputConverter::KeyStateRecorder>();
    auto keyMapper = std::make_unique<InputConverter::KeyMapper>();

    keyStateRecorder->observeKey(KeyCode::Escape);
    keyStateRecorder->observeKey(KeyCode::Up);
    keyMapper->map(KeyCode::Escape, Action::ESCAPE);
    keyMapper->map(KeyCode::Up, Action::UP);

    _manager = std::make_unique<InputConverter::Manager>(std::move(keyStateRecorder), std::move(keyMapper));

    _manager->dispatcher().registerHandler(Action::ESCAPE, std::make_shared<Handler>(*this));
  }

  void close() {
    _window.close();
  }

 private:
  struct Handler : public InputConverter::ActionHandler {
    Handler(Window& window)
      : _window(window) {}

    void handle(InputConverter::Action) override {
      _window.close();
    }

   private:
    Window& _window;
  };

 private:
  sf::Window _window;
  std::unique_ptr<InputConverter::Manager> _manager;
};

int main() {
  Window window;

  window.run();
  return 0;
}
