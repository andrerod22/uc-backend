  // Forward type declarations

  struct UC_TYPEDEF(foo);
  struct UC_TYPEDEF(baz);
  

  // Forward function declarations

  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));
  UC_PRIMITIVE(void) UC_FUNCTION(bar)(UC_REFERENCE(foo) UC_VAR(f));
  

  // Full type definitions

struct UC_TYPEDEF(foo) 
{
	UC_REFERENCE(baz) UC_VAR(b);
	

	UC_TYPEDEF(foo)() = default;
	

UC_TYPEDEF(foo)(UC_REFERENCE(baz) UC_VAR(b)) : UC_VAR(b)(UC_VAR(b)) {}
	bool operator==(const UC_TYPEDEF(foo) &rhs) const
	{
	return this->UC_VAR(b) == rhs.UC_VAR(b);
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
	return this->UC_VAR(s) == rhs.UC_VAR(s);
	}
	bool operator!=(const UC_TYPEDEF(baz) &rhs) const
	{
	return !((*this)==(rhs));
	}
};
	

