#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(foo);
  struct UC_TYPEDEF(bar);


  // Forward function declarations

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));


  // Full type definitions

struct UC_TYPEDEF(foo) 
{
	UC_PRIMITIVE(int) UC_VAR(x);
	

	UC_TYPEDEF(foo)() = default;
	

UC_TYPEDEF(foo)(UC_PRIMITIVE(int) UC_VAR(x)) : UC_VAR(x)(UC_VAR(x)) {}
	bool operator==(const UC_TYPEDEF(foo) &rhs) const
	{
	return this->UC_VAR(x) == rhs.UC_VAR(x);
	}
	bool operator!=(const UC_TYPEDEF(foo) &rhs) const
	{
	return !((*this)==(rhs));
	}
};
struct UC_TYPEDEF(bar) 
{
	UC_TYPEDEF(bar)() = default;
	

	bool operator==(const UC_TYPEDEF(bar) &rhs) const
	{
	return true;
	}
	bool operator!=(const UC_TYPEDEF(bar) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_PRIMITIVE(int) UC_VAR(i);
  UC_PRIMITIVE(float) UC_VAR(f);
	UC_VAR(i) = 3;
	UC_VAR(f) = None;
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(i) == UC_VAR(i)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(f) != UC_VAR(f)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(i) == UC_VAR(f)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(i) != UC_VAR(f)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) == uc::uc_construct<UC_REFERENCE(foo)>(3)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) != uc::uc_construct<UC_REFERENCE(foo)>(3)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) == uc::uc_construct<UC_REFERENCE(foo)>(4)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) != uc::uc_construct<UC_REFERENCE(foo)>(4)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) == nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(foo)>(3) != nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3)) == uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3))));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3)) != uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(4))));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3)) != uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3), uc::uc_construct<UC_REFERENCE(foo)>(4))));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3)) == nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_ARRAY(UC_REFERENCE(foo))>(uc::uc_construct<UC_REFERENCE(foo)>(3)) != nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(bar)>() == uc::uc_construct<UC_REFERENCE(bar)>()));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(bar)>() != uc::uc_construct<UC_REFERENCE(bar)>()));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(bar)>() == nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(uc::uc_construct<UC_REFERENCE(bar)>() != nullptr));
}


} // namespace uc

int main(int argc, char **argv) {
  uc::UC_ARRAY(uc::UC_PRIMITIVE(string)) args = uc::uc_make_array_of<uc::UC_PRIMITIVE(string)>();
  for (int i = 1; i < argc; i++) {
    uc::uc_array_push(args, uc::UC_PRIMITIVE(string)(argv[i]));
  }
  uc::UC_FUNCTION(main)(args);
  return 0;
}
