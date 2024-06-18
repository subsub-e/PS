function solution(rsp) {
    let answer = "";
    for(x of rsp){
        if(x === "2"){
            answer+="0";
        }
        else if(x === "0"){
            answer+="5";
        }
        else{
            answer+="2";
        }
    }
    return answer;
}