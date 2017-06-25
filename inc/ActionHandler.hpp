#ifndef INPUT_CONVERTER_ACTION_HANDLER_HPP
#define INPUT_CONVERTER_ACTION_HANDLER_HPP

#include "Actions.hpp"

namespace InputConverter {

class ActionHandler {
 public:
  virtual void handle(Action action) = 0;
};

} /* namespace InputConverter */

#endif
