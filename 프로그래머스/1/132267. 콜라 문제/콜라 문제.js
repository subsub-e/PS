function solution(a, b, n) {
    var answer = 0;
    let now = n;
    while(now >= a){
        let target= (Math.floor((now / a))* b);
        answer += target;
        now = target + (now % a);
    }
    return answer;
}