function solution(my_string) {
    let answer = 0;
    for(x of my_string){
        if(Number(x)){
            answer += Number(x);
        }
    }
    return answer;
}