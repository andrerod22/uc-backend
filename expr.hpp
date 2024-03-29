#ifndef UC_EXPR_HPP_c49e54971d13f14fbc634d7a0fe4b38d421279e7
#define UC_EXPR_HPP_c49e54971d13f14fbc634d7a0fe4b38d421279e7

/**
 * expr.hpp
 *
 * This file includes function template overloads for polymorphic
 * operations, specifically obtaining the id of an object, accessing
 * the length field of an object, and adding two values together.
 *
 * Project UID c49e54971d13f14fbc634d7a0fe4b38d421279e7
 */

#include "array.hpp"

namespace uc {

  // Template for obtaining the id of an object.
  template<class T>
  UC_PRIMITIVE(long) uc_id(T ref) {
    auto ptr_val = reinterpret_cast<std::uintptr_t>(ref.get());
    return static_cast<UC_PRIMITIVE(long)>(ptr_val);
  }

  // Basic template for accessing the length field of a non-array
  // object.

  template<class T>
  auto uc_length_field(T ref) -> decltype(ref->UC_VAR(length)) & {
    return ref->UC_VAR(length);
  }

  // add your overloads here

  // Template for accessing the length field of an array
  // object.  
  template <class T>
  int uc_length_field(UC_ARRAY(T) ref) {
    return uc_array_length(ref);
  } 

  // define your overloads for uc_add() here

  // string types

  std::string uc_add(std::string str, std::string str2) {
    return str + str2;
  }

  template <class T>
  auto uc_add(std::string str, T t) -> decltype(std::to_string(t)) {
    std::string t_string = std::to_string(t);
    if (*typeid(t).name() == 'b') {
      t_string = (t) ? "true" : "false";
    }
    return str + t_string;
  }

  template <class T>
  auto uc_add(T t, std::string str) -> decltype(std::to_string(t)) {
    std::string t_string = std::to_string(t);
    if (*typeid(t).name() == 'b') {
      t_string = (t) ? "true" : "false";
    }
    return t_string + str;
  }


  // numeric types
  template <class A, class B>
  auto uc_add(A a, B b) -> decltype(a + b) {
    return a + b;
  }

  /*
  // other cases 
    // string boolean , boolean string
  template <class B>
  auto uc_add(int a, B b) -> decltype(a + b) {
    return a + b;
  }

  template <class B>
  auto uc_add(double a, B b) -> decltype(a + b) {
    return a + b;
  }

  template <class B>
  auto uc_add(long a, B b) -> decltype(a + b) {
    return a + b;
  } */

} // namespace uc

#endif // UC_EXPR_HPP_c49e54971d13f14fbc634d7a0fe4b38d421279e7