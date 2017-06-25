#ifndef ACTION_MAPPER_KEY_STATE_RECORDER
#define ACTION_MAPPER_KEY_STATE_RECORDER

#include <vector>

#include <SFML/Window/Keyboard.hpp>

namespace ActionMapper {

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

} /* namespace ActionMapper */

#endif
