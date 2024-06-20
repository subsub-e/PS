function solution(my_string) {
    var answer = [];
    for(x of my_string){
        if(!isNaN(x)){
            answer.push(Number(x));
        }
    }
    answer.sort();
    return answer;
}