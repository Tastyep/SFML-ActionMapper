#ifndef INPUT_CONVERTER_MANAGER_HPP
#define INPUT_CONVERTER_MANAGER_HPP

#include <memory>

#include "ActionDispatcher.hpp"

namespace InputConverter {

class KeyStateRecorder;
class KeyMapper;

class Manager {
 public:
  Manager(std::unique_ptr<KeyStateRecorder> keyStateRecorder, std::unique_ptr<KeyMapper> keyMapper);

  void run();
  ActionDispatcher& dispatcher();

 private:
  std::unique_ptr<KeyStateRecorder> _keyStateRecorder;
  std::unique_ptr<KeyMapper> _keyMapper;
  ActionDispatcher _dispatcher;
};

} /* namespace InputConverter */
#endif
