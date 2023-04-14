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
	

