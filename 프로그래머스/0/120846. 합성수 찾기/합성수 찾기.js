function solution(n) {
    let answer = 0;
    function isPrime(x){
        for(let i = 2; i < x; i++){
            if(x % i == 0){
                return true;
            }
        }
        return false;
    }
    for(let i = 4; i <= n; i++){
        if(isPrime(i)){
            answer++;
        }
    }
    return answer;
}