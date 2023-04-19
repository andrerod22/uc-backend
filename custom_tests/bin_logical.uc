void main(string[] args)(boolean a, boolean b) {
    a = 1 > 2 && 2 < 1;
    b = 0 == 0 || 1 == 1;
    println("a = " + bool_to_string(a) + ", b = " + bool_to_string(b));
}

string bool_to_string(boolean b)(){
    if (b){
        return "true";
    }
    else {
        return "false";
    }
}