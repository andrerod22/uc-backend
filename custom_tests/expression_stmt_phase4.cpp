#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations



  // Forward function declarations

  UC_PRIMITIVE(int) UC_FUNCTION(main)(UC_PRIMITIVE(int) UC_VAR(a), UC_PRIMITIVE(int) UC_VAR(b));


  // Full type definitions



  // Full function definitions

  UC_PRIMITIVE(int) UC_FUNCTION(main)(UC_PRIMITIVE(int) UC_VAR(a), UC_PRIMITIVE(int) UC_VAR(b))
  {
	UC_VAR(a) = 1;
	UC_VAR(b) = 2;
	UC_VAR(a) > UC_VAR(b);
	return UC_VAR(a);
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
