#include "Manager.hpp"

#include <iostream>
#include <utility>

#include "KeyMapper.hpp"
#include "KeyStateRecorder.hpp"

namespace InputConverter {

Manager::Manager(std::unique_ptr<KeyStateRecorder> keyStateRecorder, std::unique_ptr<KeyMapper> keyMapper)
  : _keyStateRecorder(std::move(keyStateRecorder))
  , _keyMapper(std::move(keyMapper)) {}

void Manager::run() {
  _keyStateRecorder->checkKeys();
  const auto pressedKeys = _keyStateRecorder->pressedKeys();

  for (auto keyCode : pressedKeys) {
    auto action = (*_keyMapper)[keyCode];

    std::cout << "key Pressed: " << (int)keyCode << " action: " << action << std::endl;

    _dispatcher.dispatch(action);
  }
}

ActionDispatcher& Manager::dispatcher() {
  return _dispatcher;
}

} /* namespace InputConverter */
