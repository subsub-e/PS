const map = {
    1 : 5,
    2 : 4,
    3 : 3,
    4 : 2,
    5 : 1,
    6 : 0,
    7 : 6,
}

function calculate(ti){
    let hour = Math.floor(ti / 100);
    let minute = ti % 100;
    
    if(minute >= 50){
        return ti + 50;
    }
    else{
        return ti + 10;
    }
}

function solution(schedules, timelogs, startday) {
    let answer = 0;
    
    for(let i = 0; i < timelogs.length; i++){
        let flag = 0;
        for(let j = 0; j < 7; j++){
            if(startday === 7 && j === 0){
                continue;
            }
            if(map[startday] === j || map[startday] + 1 === j){
                continue;
            }
            if(timelogs[i][j] > calculate(schedules[i])){
                flag = 1;
                // console.log(i, j, timelogs[i][j])
                break;
            }
        }
        
        if(flag === 0){
            answer++;
        }
    }
    return answer;
}