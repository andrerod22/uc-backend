#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations



  // Forward function declarations

  UC_PRIMITIVE(void)UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));


  // Full type definitions



  // Full function definitions

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
	UC_FUNCTION(println)(uc::uc_add(""s, false));
	UC_FUNCTION(println)(uc::uc_add(""s, true));
	UC_FUNCTION(println)(uc::uc_add(""s, "hello"s));
	UC_FUNCTION(println)(uc::uc_add(""s, 3));
	UC_FUNCTION(println)(uc::uc_add(""s, 31415926535L));
	UC_FUNCTION(println)(uc::uc_add(""s, 3.0));
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
