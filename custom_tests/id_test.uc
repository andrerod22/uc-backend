void main(string[] args)(int a, int b) {
    a = 42;
    b = #a;
    println("a = " + a + ", b = " + b);
}