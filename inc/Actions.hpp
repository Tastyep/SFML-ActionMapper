#ifndef INPUT_CONVERTER_ACTIONS_HPP
#define INPUT_CONVERTER_ACTIONS_HPP

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

template <Action a>
struct Type {};

} /* namespace InputConverter */

#endif
