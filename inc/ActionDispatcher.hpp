#ifndef INPUT_CONVERTER_ACTION_DISPATCHER_HPP
#define INPUT_CONVERTER_ACTION_DISPATCHER_HPP

#include <memory>
#include <unordered_map>
#include <vector>

#include "ActionHandler.hpp"

namespace InputConverter {

class ActionDispatcher {
 public:
  ActionDispatcher() = default;

  void registerHandler(Action action, std::shared_ptr<ActionHandler> handler);
  void dispatch(Action action) const;

 private:
  std::unordered_map<Action, std::vector<std::shared_ptr<ActionHandler>>> _handlers;
};

} /* namespace InputConverter */

#endif
