function solution(name, yearning, photo) {
    var answer = [];
    const map = new Map();
    for(let i = 0; i < name.length; i++){
        map.set(name[i], yearning[i]);
    }
    
    for(let photoArr of photo){
        let cnt = 0;
        for(let pho of photoArr){
            if(map.has(pho)){
                cnt += map.get(pho);
            }
        }
        answer.push(cnt);
    }
    return answer;
}