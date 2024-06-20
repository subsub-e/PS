function solution(array, n) {
    let minans = 100001;
    let answer = 0;
    const newArray = array.sort();
    for(x of newArray){
        if(Math.abs(x - n) < minans){
            minans = Math.abs(x - n);
            answer = x;
        }
    }
    return answer;
}