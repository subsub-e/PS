const map = {};

function solution(keymap, targets) {
    let answer = [];
    
    for(let i = 0; i < keymap.length; i++){
        for(let j = 0; j < keymap[i].length; j++){
            if(!(keymap[i][j] in map)){
                map[keymap[i][j]] = j + 1;
                continue;
            }
            if(map[keymap[i][j]] && map[keymap[i][j]] > j + 1){
                map[keymap[i][j]] = j + 1;
            }
        }
    }
    
    for(let str of targets){
        let cnt = 0;
        for(let c of str){
            if(!(c in map)){
                cnt = 0;
                break;
            }
            else{
                cnt += map[c];
            }
        }
        if(cnt > 0){
            answer.push(cnt);
        }
        else{
            answer.push(-1);
        }
    }
    return answer;
}