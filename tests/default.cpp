#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(foo);
  struct UC_TYPEDEF(bar);
  struct UC_TYPEDEF(baz);


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
	UC_REFERENCE(foo) UC_VAR(f);
	

	UC_PRIMITIVE(int) UC_VAR(x);
	

	UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(a);
	

	UC_TYPEDEF(bar)() = default;
	

UC_TYPEDEF(bar)(UC_REFERENCE(foo) UC_VAR(f), UC_PRIMITIVE(int) UC_VAR(x), UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(a)) : UC_VAR(f)(UC_VAR(f)), UC_VAR(x)(UC_VAR(x)), UC_VAR(a)(UC_VAR(a)) {}
	bool operator==(const UC_TYPEDEF(bar) &rhs) const
	{
	return this->UC_VAR(f) == rhs.UC_VAR(f) && this->UC_VAR(x) == rhs.UC_VAR(x) && this->UC_VAR(a) == rhs.UC_VAR(a);
	}
	bool operator!=(const UC_TYPEDEF(bar) &rhs) const
	{
	return !((*this)==(rhs));
	}
};
struct UC_TYPEDEF(baz) 
{
	UC_TYPEDEF(baz)() = default;
	

	bool operator==(const UC_TYPEDEF(baz) &rhs) const
	{
	return true;
	}
	bool operator!=(const UC_TYPEDEF(baz) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))(UC_REFERENCE(foo) UC_VAR(f), UC_REFERENCE(bar) UC_VAR(b), UC_REFERENCE(baz) UC_VAR(z))
{
	UC_VAR(f) = uc::uc_construct<UC_REFERENCE(foo)>();
	UC_VAR(b) = uc::uc_construct<UC_REFERENCE(bar)>();
	UC_VAR(z) = uc::uc_construct<UC_REFERENCE(baz)>();
	UC_FUNCTION(println)(UC_FUNCTION(int_to_string)(UC_VAR(f)->UC_VAR(x)));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(b)->UC_VAR(f) == nullptr));
	UC_FUNCTION(println)(UC_FUNCTION(boolean_to_string)(UC_VAR(b)->UC_VAR(a) == nullptr));
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
