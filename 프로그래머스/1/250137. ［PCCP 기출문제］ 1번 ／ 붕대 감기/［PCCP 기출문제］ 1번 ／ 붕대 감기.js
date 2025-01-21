function solution(bandage, health, attacks) {
    let answer = health;
    
    let lastTime = attacks[0][0];
    
    for(const element of attacks){
        if(lastTime === element[0]){
            answer -= element[1];
        }
        else{
            let t = element[0] - 1 - lastTime;
            if(t >= bandage[0]){
                answer = answer + (t * bandage[1]) + (bandage[2] * Math.floor(t / bandage[0]));
            }
            else{
                if(t >= 0){
                    answer = answer + (t * bandage[1]);
                }
            }
            if(answer > health){
                answer = health;
            }
            answer -= element[1];
            if(answer <= 0){
                answer = -1;
                break;
            }
            
            lastTime = element[0];
            console.log(answer);
        }
    }
    return answer;
}