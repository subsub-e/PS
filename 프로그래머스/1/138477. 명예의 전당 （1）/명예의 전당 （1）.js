function solution(k, score) {
    let answer = [];
    
    let arr = [];
    for(let s of score){
        if(arr.length === 0){
            arr.push(s);
            answer.push(s);
            continue;
        }
        arr.push(s);
        arr.sort((a, b) => b - a);
        if(arr.length === k + 1){
            arr.pop();
        }
        answer.push(arr[arr.length - 1]);
    }
    return answer;
}