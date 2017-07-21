#ifndef INPUT_CONVERTER_MANAGER_HPP
#define INPUT_CONVERTER_MANAGER_HPP

#include <memory>

#include <iostream>

#include "ActionDispatcher.hpp"
#include "KeyMapper.hpp"
#include "KeyStateRecorder.hpp"

namespace InputConverter {

template <typename Action>
class Manager {
 public:
  Manager()
    : _dispatcher(std::make_shared<Dispatcher<Action>>()) {}

  void run() {
    _keyStateRecorder.checkKeys();
    const auto pressedKeys = _keyStateRecorder.pressedKeys();

    for (auto keyCode : pressedKeys) {
      auto action = _keyMapper[keyCode];

      // Cout as an example.
      std::cout << "key Pressed: " << (int)keyCode << " action: " << action << std::endl;

      _dispatcher->dispatch(action);
    }
  }

  void bind(sf::Keyboard::Key key, Action action) {
    _keyStateRecorder.observeKey(key);
    _keyMapper.map(key, action);
  }

  bool unbind(sf::Keyboard::Key key) {
    if (_keyStateRecorder.forgetKey(key)) {
      _keyMapper.unmap(key);
      return true;
    }
    return false;
  }

 public:
  std::shared_ptr<Dispatcher<Action>> dispatcher() const {
    return _dispatcher;
  }

 private:
  KeyStateRecorder _keyStateRecorder;
  KeyMapper<Action> _keyMapper;
  std::shared_ptr<Dispatcher<Action>> _dispatcher;
};

} /* namespace InputConverter */
#endif
