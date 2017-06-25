#ifndef INPUT_CONVERTER_HASH_GENERATOR_HPP
#define INPUT_CONVERTER_HASH_GENERATOR_HPP

#include <typeindex>

namespace InputConverter {

class HashGenerator {
 public:
  template <typename T>
  static size_t hash() {
    return std::type_index(typeid(T)).hash_code();
  }
};

} /* namespace InputConverter */

#endif
