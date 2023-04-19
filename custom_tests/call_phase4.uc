void main(string[] args)(int sum) {
    sum = add(5, 7);
    println("5 + 7 = " + int_to_string(sum));
}


int add(int a, int b)() {
    return a + b;
}