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
  Manager(std::unique_ptr<KeyStateRecorder> keyStateRecorder, std::unique_ptr<KeyMapper<Action>> keyMapper)
    : _keyStateRecorder(std::move(keyStateRecorder))
    , _keyMapper(std::move(keyMapper)) {}

  void run() {
    _keyStateRecorder->checkKeys();
    const auto pressedKeys = _keyStateRecorder->pressedKeys();

    for (auto keyCode : pressedKeys) {
      auto action = (*_keyMapper)[keyCode];

      // Cout as an example.
      std::cout << "key Pressed: " << (int)keyCode << " action: " << action << std::endl;

      _dispatcher.dispatch(action);
    }
  }

  Dispatcher<Action>& dispatcher() {
    return _dispatcher;
  }

 private:
  std::unique_ptr<KeyStateRecorder> _keyStateRecorder;
  std::unique_ptr<KeyMapper<Action>> _keyMapper;
  Dispatcher<Action> _dispatcher;
};

} /* namespace InputConverter */
#endif
