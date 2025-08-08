function solution(ingredient) {
    var answer = 0;
    
    let arr = [];
    for(let num of ingredient){
        
        
        if(num === 1 && arr.length >= 3 && arr[arr.length - 1] === 3 && arr[arr.length - 2] === 2 && arr[arr.length - 3] === 1){
            answer++;
            arr.pop();
            arr.pop();
            arr.pop();
        }
        else{
            arr.push(num);
        }
    }
    
    return answer;
}