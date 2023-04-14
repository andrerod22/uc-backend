  // Forward type declarations

  struct UC_TYPEDEF(foo);
  

  // Forward function declarations

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(void) UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f));
  

  // Full type definitions

struct UC_TYPEDEF(foo) 
{
	UC_PRIMITIVE(int) UC_VAR(x);
	

	UC_PRIMITIVE(string) UC_VAR(length);
	

	UC_TYPEDEF(foo)() = default;
	

UC_TYPEDEF(foo)(UC_PRIMITIVE(int) UC_VAR(x), UC_PRIMITIVE(string) UC_VAR(length)) : UC_VAR(x)(UC_VAR(x)), UC_VAR(length)(UC_VAR(length)) {}
	bool operator==(const UC_TYPEDEF(foo) &rhs) const
	{
	return this->UC_VAR(x) == rhs.UC_VAR(x) && this->UC_VAR(length) == rhs.UC_VAR(length);
	}
	bool operator!=(const UC_TYPEDEF(foo) &rhs) const
	{
	return !((*this)==(rhs));
	}
};
	

