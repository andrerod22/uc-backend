#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(foo);
  struct UC_TYPEDEF(baz);


  // Forward function declarations

  UC_PRIMITIVE(void)UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(void)UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f));


  // Full type definitions

struct UC_TYPEDEF(foo) 
{
	UC_REFERENCE(baz) UC_VAR(b);
	

	UC_TYPEDEF(foo)() = default;
	

UC_TYPEDEF(foo)(UC_REFERENCE(baz) UC_VAR(b)) : UC_VAR(b)(UC_VAR(b)) {}
	bool operator==(const UC_TYPEDEF(foo) &rhs) const
	{
	return this->UC_VAR(b)== rhs.UC_VAR(b);
	}
	bool operator!=(const UC_TYPEDEF(foo) &rhs) const
	{
	return !((*this)==(rhs));
	}
};
struct UC_TYPEDEF(baz) 
{
	UC_PRIMITIVE(string) UC_VAR(s);
	

	UC_TYPEDEF(baz)() = default;
	

UC_TYPEDEF(baz)(UC_PRIMITIVE(string) UC_VAR(s)) : UC_VAR(s)(UC_VAR(s)) {}
	bool operator==(const UC_TYPEDEF(baz) &rhs) const
	{
	return this->UC_VAR(s)== rhs.UC_VAR(s);
	}
	bool operator!=(const UC_TYPEDEF(baz) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_REFERENCE(foo)UC_VAR(f);
	(UC_VAR(f) = uc::uc_construct<UC_REFERENCE(foo)>(uc::uc_construct<UC_REFERENCE(baz)>(uc::uc_array_index(UC_VAR(args), 0))));
	UC_FUNCTION(bar)(UC_VAR(f));
}
	UC_PRIMITIVE(void) UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f))
{
	UC_FUNCTION(println)(UC_VAR(f)->UC_VAR(b)->UC_VAR(s));
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
