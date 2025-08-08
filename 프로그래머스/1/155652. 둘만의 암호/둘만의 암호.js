function solution(s, skip, index) {
    let answer = [];
    // console.log('a'.charCodeAt(0));
    
    const ss = new Set();
    for(let i = 0; i < skip.length; i++){
        ss.add(skip.charCodeAt(i));
    }
    
    for(let c of s){
        let cnt = 0;
        let now = c.charCodeAt(0);
        while(cnt < index){
            now++;
            if(now === 123){
                now = 97;
            }
            if(!(ss.has(now))){
                cnt++;
            }
        }
        // console.log(String.fromCharCode(now));
        answer.push(String.fromCharCode(now));
    }
    
    return answer.join('');
}