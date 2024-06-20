function solution(i, j, k) {
    let answer = 0;
    for(let t = i; t <= j; t++){
        if(String(t).split('').includes(String(k))){
            for(x of String(t).split('')){
                if(x == String(k)){
                    answer++;
                }
            }
        }
    }
    return answer;
}