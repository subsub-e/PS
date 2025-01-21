function solution(n, m, section) {
    let answer = 0;
    let index = 1;
    let i = 0;
    while(index <= n && i < section.length){
        index = section[i];
        index += m;
        answer += 1;
        while(index > section[i]){
            i += 1;
        }
    }
    return answer;
}