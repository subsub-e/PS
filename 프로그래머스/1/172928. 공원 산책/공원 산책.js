function solution(park, routes) {
    var answer = [];
    
    let start;
    
    const dxdy = {
        E : [0, 1],
        S : [1, 0],
        N : [-1, 0],
        W : [0, -1],
    };
    
    for(let i = 0; i < park.length; i++){
        for(let j = 0; j < park[i].length; j++){
            if(park[i][j] == 'S'){
                start = [i, j];
            }
        }
    }
    
    for(const route of routes){
        let dir = route.split(' ')[0];
        let distance = parseInt(route.split(' ')[1]);
        
        let nx = start[0];
        let ny = start[1];
        let flag = 0;
        
        for(let i = 0; i < distance; i++){
            nx += dxdy[dir][0];
            ny += dxdy[dir][1];
            
            if(!(0 <= nx && nx < park.length && 0 <= ny && ny < park[0].length && park[nx][ny] != 'X')){
                flag = 1;
                break;
            }
        }
        if(flag === 0){
            start[0] = nx;
            start[1] = ny;
        }
    }
    
    answer.push(start[0]);
    answer.push(start[1]);
    return answer;
}