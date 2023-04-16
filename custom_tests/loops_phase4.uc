void main(string[] args)(int i) {
    i = 0;
    while(i < 3){
        ++i;
        break;
    }
    i = 0;
    while(i < 3){
        ++i;
        continue;
    }
    i = 0;
    for(; i < 3; ++i){

    }

    for(int j = 0; j < 3; ++j){

    }

    for(; ; ;){
        return;
    }
}
