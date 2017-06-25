#ifndef INPUT_CONVERTER_KEY_STATE_RECORDER_HPP
#define INPUT_CONVERTER_KEY_STATE_RECORDER_HPP

#include <vector>

#include <SFML/Window/Keyboard.hpp>

namespace InputConverter {

using KeyCode = sf::Keyboard::Key;

class KeyStateRecorder {
 public:
  KeyStateRecorder() = default;

  void observeKey(KeyCode key);
  void checkKeys();
  std::vector<KeyCode> pressedKeys() const;

 private:
  struct KeyState {
    explicit KeyState(KeyCode code, bool state = false)
      : code(code)
      , state(state) {}

    KeyCode code;
    bool state;
  };

 private:
  std::vector<KeyState> _keys;
};

} /* namespace InputConverter */

#endif
