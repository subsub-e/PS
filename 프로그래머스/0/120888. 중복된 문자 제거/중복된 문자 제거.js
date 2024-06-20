function solution(my_string) {
    var answer = '';
    for(x of my_string){
        if(!answer.includes(x)){
            answer += x;
        }
    }
    return answer;
}