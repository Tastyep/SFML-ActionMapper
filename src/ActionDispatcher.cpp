#include "ActionDispatcher.hpp"

#include <cassert>

namespace InputConverter {

void ActionDispatcher::registerHandler(Action action, std::shared_ptr<ActionHandler> handler) {
  _handlers[action].emplace_back(std::move(handler));
}

void ActionDispatcher::dispatch(Action action) const {
  auto it = _handlers.find(action);

  if (it != _handlers.end()) {
    for (const auto& handler : it->second) {
      handler->handle(action);
    }
  }
}

} /* namespace InputConverter */
