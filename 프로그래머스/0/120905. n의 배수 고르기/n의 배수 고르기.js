function solution(n, numlist) {
    let answer = [];
    for(x of numlist){
        if(x % n == 0){
            answer.push(x);
        }
    }
    return answer;
}