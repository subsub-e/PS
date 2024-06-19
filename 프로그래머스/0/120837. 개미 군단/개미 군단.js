function solution(hp) {
    let answer = 0;
    while(hp > 0){
        if((hp / 5) >= 1){
            answer += Math.floor(hp / 5);
            hp -= Math.floor(hp / 5)  * 5;
        }
        else if(hp / 3 >= 1){
            answer += Math.floor(hp / 3);
            hp -= Math.floor(hp / 3)  * 3;
        }
        else{
            answer += hp;
            hp = 0;
        }
    }
    return answer;
}