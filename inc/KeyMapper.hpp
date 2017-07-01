#ifndef INPUT_CONVERTER_KEY_MAPPER_HPP
#define INPUT_CONVERTER_KEY_MAPPER_HPP

#include <cassert>
#include <unordered_map>

#include <SFML/Window/Keyboard.hpp>

namespace InputConverter {

using KeyCode = sf::Keyboard::Key;

template <typename Action>
class KeyMapper {
 public:
  KeyMapper() = default;

  void map(KeyCode code, Action a) {
    _keyMapper[code] = a;
  }

  Action operator[](KeyCode code) const {
    auto it = _keyMapper.find(code);
    assert(it != _keyMapper.end());

    return it->second;
  }

 private:
  std::unordered_map<KeyCode, Action> _keyMapper;
};

} /* namespace InputConverter */

#endif
