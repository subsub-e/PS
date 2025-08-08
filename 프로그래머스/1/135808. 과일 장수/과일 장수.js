function solution(k, m, score) {
    let answer = 0;
    
    score.sort((a, b) => b - a);
    
    let arr = [];
    
    for(let apple of score){
        arr.push(apple);
        
        if(arr.length === m){
            answer += arr[arr.length - 1] * m;
            arr = [];
        }
    }
    return answer;
}