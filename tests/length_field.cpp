#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(foo);


  // Forward function declarations

  UC_PRIMITIVE(void)UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(void)UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f));


  // Full type definitions

struct UC_TYPEDEF(foo) 
{
	UC_PRIMITIVE(int) UC_VAR(x);
	

	UC_PRIMITIVE(string) UC_VAR(length);
	

	UC_TYPEDEF(foo)() = default;
	

UC_TYPEDEF(foo)(UC_PRIMITIVE(int) UC_VAR(x), UC_PRIMITIVE(string) UC_VAR(length)) : UC_VAR(x)(UC_VAR(x)), UC_VAR(length)(UC_VAR(length)) {}
	bool operator==(const UC_TYPEDEF(foo) &rhs) const
	{
	return this->UC_VAR(x)== rhs.UC_VAR(x) && this->UC_VAR(length)== rhs.UC_VAR(length);
	}
	bool operator!=(const UC_TYPEDEF(foo) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_REFERENCE(foo)UC_VAR(f);
	UC_FUNCTION(println)(uc::uc_add(""s, uc::uc_length_field(UC_VAR(args))));
	(UC_VAR(f) = uc::uc_construct<UC_REFERENCE(foo)>(3, "hello"s));
	UC_FUNCTION(println)(uc::uc_length_field(UC_VAR(f)));
	(uc::uc_length_field(UC_VAR(f)) = "world"s);
	UC_FUNCTION(println)(uc::uc_length_field(UC_VAR(f)));
}
	UC_PRIMITIVE(void) UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f))
{
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
