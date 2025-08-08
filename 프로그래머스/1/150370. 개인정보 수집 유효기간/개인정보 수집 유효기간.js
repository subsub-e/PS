function calculate(arr, num){
    let year = Number(arr[0]);
    let month = Number(arr[1]);
    let date = Number(arr[2]);
    
    year += Math.floor(num / 12);
    month += num % 12;
    date--;
    
    if(date === 0){
        date = 28;
        month--;
    }
    
    if(month > 12){
        year++;
        month -= 12;
    }
    
    return [year, String(month).padStart(2, 0), String(date).padStart(2, 0)].join('.');
}

function simulate(target, today){
    let x = Number(target.split('.').join(''));
    let y = Number(today.split('.').join(''));
    
    // console.log(x, y);
    
    if(x < y){
        return true;
    }
    else{
        return false;
    }
}

function solution(today, terms, privacies) {
    let answer = [];
    
    const map = {};
    for(let str of terms){
        let [a, b] = str.split(' ');
        map[a] = b;
    }
    
    for(let i = 0; i < privacies.length; i++){
        let str = privacies[i];
        let [date, a] = str.split(' ');
        
        let d = calculate(date.split('.'), map[a]);
        if(simulate(d, today)){
            answer.push(i + 1);
        }
    }
    
    return answer;
}