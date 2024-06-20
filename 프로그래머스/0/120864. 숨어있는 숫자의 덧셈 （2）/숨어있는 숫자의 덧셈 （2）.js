function solution(my_string) {
    let str = "";
    let answer = 0;
    for(x of my_string){
        if(isNaN(x)){
            if(str != ""){
                answer += parseInt(str);
                str = "";
            }
        }
        else{
            str += x;
        }
    }
    if(str != ""){
        answer += parseInt(str);
    }
    return answer;
}