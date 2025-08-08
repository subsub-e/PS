function solution(s) {
    let answer = 0;
    
    let cnt1 = 0;
    let cnt2 = 0;
    let target = null;
    for(let i = 0; i < s.length; i++){
        if(target === null){
            target = s[i];
            cnt1 = 1;
        }
        else{
            if(target === s[i]){
                cnt1++;
            }
            else{
                cnt2++;
                if(cnt1 === cnt2){
                    target = null;
                    cnt1 = 0;
                    cnt2 = 0;
                    answer++;
                }
            }
        }
    }
    
    if(cnt1 !== cnt2){
        answer++;
    }
    return answer;
}