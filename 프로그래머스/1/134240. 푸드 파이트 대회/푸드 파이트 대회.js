function solution(food) {
    let answer = '';
    
    for(let i = 1; i < food.length; i++){
        let now = food[i];
        
        answer += (String(i).repeat(Math.floor(now / 2)));
    }
    let temp = answer.split('').reverse().join('');
    answer += "0" + temp;
    
    return answer;
}