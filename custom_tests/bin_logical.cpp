#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations



  // Forward function declarations

  UC_PRIMITIVE(void)UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(string)UC_FUNCTION(bool_to_string)(UC_PRIMITIVE(boolean) UC_VAR(b));


  // Full type definitions



  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_PRIMITIVE(boolean)UC_VAR(a);
  UC_PRIMITIVE(boolean)UC_VAR(b);
	(UC_VAR(a) = ((1 > 2) && (2 < 1)));
	(UC_VAR(b) = ((0 == 0) || (1 == 1)));
	UC_FUNCTION(println)(uc::uc_add(uc::uc_add(uc::uc_add("a = "s, UC_FUNCTION(bool_to_string)(UC_VAR(a))), ", b = "s), UC_FUNCTION(bool_to_string)(UC_VAR(b))));
}
	UC_PRIMITIVE(string) UC_FUNCTION(bool_to_string)(UC_PRIMITIVE(boolean) UC_VAR(b))
{
	if (UC_VAR(b)) 
	{
	return "true"s;
	}
	else 
	{
	return "false"s;
	}
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
