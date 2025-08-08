function simulate(num){
    let cnt = 0;
    
    for(let i = 1; i <= Math.sqrt(num); i++){
        if(num % i === 0){
            cnt+=2;
        }
        if(i * i === num){
            cnt--;
        }
    }
    return cnt;
}

function solution(number, limit, power) {
    let answer = 0;
    
    for(let i = 1; i <= number; i++){
        let cnt = simulate(i);
        
        if(cnt > limit){
            answer += power;
        }
        else{
            answer += cnt;
        }
    }
    
    return answer;
}