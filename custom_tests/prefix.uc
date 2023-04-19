void main(string[] args)(int a, int b) {
    a = -42;
    b = -a;
    println("a = " + int_to_string(a) + ", b = " + int_to_string(b));
}