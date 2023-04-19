#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations



  // Forward function declarations

  UC_PRIMITIVE(void)UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(int)UC_FUNCTION(add)(UC_PRIMITIVE(int) UC_VAR(a), UC_PRIMITIVE(int) UC_VAR(b));


  // Full type definitions



  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
  UC_PRIMITIVE(int)UC_VAR(sum);
	(UC_VAR(sum) = UC_FUNCTION(add)(5, 7));
	UC_FUNCTION(println)(uc::uc_add("5 + 7 = "s, UC_FUNCTION(int_to_string)(UC_VAR(sum))));
}
	UC_PRIMITIVE(int) UC_FUNCTION(add)(UC_PRIMITIVE(int) UC_VAR(a), UC_PRIMITIVE(int) UC_VAR(b))
{
	return uc::uc_add(UC_VAR(a), UC_VAR(b));
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
