#include "KeyStateRecorder.hpp"

#include <algorithm>

namespace InputConverter {

void KeyStateRecorder::observeKey(KeyCode keyCode) {
  if (std::find_if(_keys.begin(), _keys.end(),                                 //
                   [keyCode](const auto& key) { return key.code == keyCode; }) //
      == _keys.end()) {
    _keys.emplace_back(keyCode);
  }
}

void KeyStateRecorder::checkKeys() {
  for (auto& key : _keys) {
    key.state = sf::Keyboard::isKeyPressed(key.code);
  }
}

std::vector<KeyCode> KeyStateRecorder::pressedKeys() const {
  std::vector<KeyCode> pressedKeys;

  for (const auto& key : _keys) {
    if (key.state) {
      pressedKeys.push_back(key.code);
    }
  }
  return pressedKeys;
}

} /* namespace InputConverter */
