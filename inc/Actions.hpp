#ifndef INPUT_CONVERTER_ACTIONS_HPP
#define INPUT_CONVERTER_ACTIONS_HPP

#include <iostream>
#include <type_traits>

namespace InputConverter {

// clang-format off
enum class Action {
  ESCAPE,
  ACTION,
  JUMP,
  LEFT,
  RIGHT,
  UP,
  DOWN
};
// clang-format om

inline std::ostream& operator<<(std::ostream& os, Action action) {
  os << static_cast<std::underlying_type<Action>::type>(action);
  return os;
}

} /* namespace InputConverter */

#endif
