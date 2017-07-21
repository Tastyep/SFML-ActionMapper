#ifndef INPUT_CONVERTER_ACTION_DISPATCHER_HPP
#define INPUT_CONVERTER_ACTION_DISPATCHER_HPP

#include <memory>
#include <unordered_map>
#include <vector>

#include "ActionHandler.hpp"

namespace InputConverter {

template <typename Action>
class Dispatcher {
 public:
  void registerHandler(Action action, std::shared_ptr<ActionHandler<Action>> handler) {
    _handlers[action].emplace_back(std::move(handler));
  }

  void dispatch(Action action) const {
    auto it = _handlers.find(action);

    if (it != _handlers.end()) {
      for (const auto& handler : it->second) {
        handler->handle(action);
      }
    }
  }

 private:
  std::unordered_map<Action, std::vector<std::shared_ptr<ActionHandler<Action>>>> _handlers;
};

} /* namespace InputConverter */

#endif
