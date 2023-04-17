void main(string[] args)(test t) {
    // Checks that we properly created a string and not a const char: 
    t = new test(1, "Hello World");
    println("t.x = " + int_to_string(t.x) + "\n");
    println("t.s = " + t.s + "\n");

}
struct test(int x, string s);