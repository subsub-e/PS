function solution(n) {
    let fact = 1;
    let index = 1;
    while(fact <= n){
        fact *= index++;
    }
    return index - 2;
}