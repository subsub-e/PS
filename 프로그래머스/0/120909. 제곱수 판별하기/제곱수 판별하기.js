function solution(n) {
    if(String(Math.sqrt(n, 2)).includes('.')){
        return 2;
    }
    return 1;
}