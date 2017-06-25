#ifndef INPUT_CONVERTER_KEY_MAPPER_HPP
#define INPUT_CONVERTER_KEY_MAPPER_HPP

#include <cassert>
#include <unordered_map>

#include "HashGenerator.hpp"

namespace InputConverter {

using KeyCode = sf::Keyboard::Key;

class KeyMapper {
 public:
  KeyMapper() = default;

  template <typename Action>
  void map(KeyCode code) {
    _keyMapper[code] = HashGenerator::hash<Action>();
  }

  size_t operator[](KeyCode code) const {
    auto it = _keyMapper.find(code);
    assert(it != _keyMapper.end());

    return it->second;
  }

 private:
  std::unordered_map<KeyCode, size_t> _keyMapper;
};

} /* namespace InputConverter */

#endif
