function solution(n, w, num) {
    let answer = 0;
    let arr = [];
    
    let temp = [];
    for(let i = 1; i <= n; i++){
        if(Math.floor((i - 1) / w) % 2 === 0){
            temp.push(i);
        }
        else{
            temp.unshift(i);
        }
        if(i % w === 0){
            arr.push(temp);
            temp = [];
        }
    }
    

    
    if(temp.length !== 0){
        let now_temp = n;
        if(Math.floor((now_temp - 1) / w) % 2 === 0){
            while(now_temp % w !== 0){
                temp.push(0);
                now_temp++;
            }
        }
        else{
            while(now_temp % w !== 0){
                temp.unshift(0);
                now_temp++;
            }
        }
            arr.push(temp);

    }
    
    
    for(let i = 0; i < arr.length; i++){
        for(let j = 0; j < arr[i].length; j++){
            if(arr[i][j] === num){
                let now_index = i;
                while(now_index < arr.length){
                    if(arr[now_index][j] === 0){
                        break;
                    }
                    now_index++;
                    answer++;
                }
            }
        }
    }
    
    return answer;
}