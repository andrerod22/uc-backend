#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(test);


  // Forward function declarations

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));


  // Full type definitions

struct UC_TYPEDEF(test) 
{
	UC_PRIMITIVE(int) UC_VAR(x);
	

	UC_PRIMITIVE(string) UC_VAR(s);
	

	UC_TYPEDEF(test)() = default;
	

UC_TYPEDEF(test)(UC_PRIMITIVE(int) UC_VAR(x), UC_PRIMITIVE(string) UC_VAR(s)) : UC_VAR(x)(UC_VAR(x)), UC_VAR(s)(UC_VAR(s)) {}
	bool operator==(const UC_TYPEDEF(test) &rhs) const
	{
	return this->UC_VAR(x) == rhs.UC_VAR(x) && this->UC_VAR(s) == rhs.UC_VAR(s);
	}
	bool operator!=(const UC_TYPEDEF(test) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_REFERENCE(test) UC_VAR(t);
	UC_VAR(t) = uc::uc_construct<UC_REFERENCE(test)>(1, "Hello World"s);
	UC_FUNCTION(println)(uc::uc_add(uc::uc_add("t.x = "s, UC_FUNCTION(int_to_string)(UC_VAR(t)->UC_VAR(x))), "\n"s));
	UC_FUNCTION(println)(uc::uc_add(uc::uc_add("t.s = "s, UC_VAR(t)->UC_VAR(s)), "\n"s));
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
