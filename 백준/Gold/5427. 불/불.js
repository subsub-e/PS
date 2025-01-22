const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


let t = Number(input.shift());
const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];

function simulate(){
    let [m, n] = input.shift().split(' ').map(Number);
    let array = Array.from({length : n}, () => {
        Array.from({length : m});
    });

    let st, en;
    let visited = Array.from({length : n}, () => Array.from({length : m}).fill(0));
    


    let queue = [];

    for(let i = 0; i < n; i++){
        array[i] = input.shift().split('');
        for(let j = 0; j < m; j++){
            if(array[i][j] === '@'){
                st = i;
                en = j;
            }
            if(array[i][j] === '*'){
                queue.push([i, j]);
                visited[i][j] = 1;
            }
        }
    }

    let idx = 0;
    while(queue.length > idx){
        let [x, y] = queue[idx];
        idx++;

        
        for(let i = 0; i < 4; i++){
            let nx = x + dx[i];
            let ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && array[nx][ny] != '#'){
                visited[nx][ny] = visited[x][y] + 1;
                queue.push([nx, ny]);
            }
        }
    }

    queue = [];

    queue.push([st, en, 1]);
    let people = Array.from({length : n}, () => Array.from({length : m}).fill(0));
    people[st][en] = 1;

    let idx2 = 0;
    while(queue.length > idx2){
        let [x, y, cnt] = queue[idx2];
        idx2++;
        //console.log(x, y, cnt);
        if (x === 0 || x === n - 1 || y === 0 || y === m - 1) {
            console.log(cnt);
            return;
        }

        for(let i = 0; i < 4; i++){
            let nx = x + dx[i];
            let ny = y + dy[i];

            if (
                0 <= nx && nx < n &&
                0 <= ny && ny < m &&
                array[nx][ny] != '#' &&
                !people[nx][ny]
            ) {
                if(visited[nx][ny] == 0){
                    if (nx === 0 || nx === n - 1 || ny === 0 || ny === m - 1) {
                        console.log(cnt + 1);
                        return;
                    }
                    queue.push([nx, ny, cnt + 1]);
                    people[nx][ny] = 1;
                }
                else if(visited[nx][ny] > (cnt + 1)){
                    if (nx === 0 || nx === n - 1 || ny === 0 || ny === m - 1) {
                        console.log(cnt + 1);
                        return;
                    }
                    queue.push([nx, ny, cnt + 1]);
                    people[nx][ny] = 1;
                }
            }
            
        }
    }

    console.log("IMPOSSIBLE");
}


while(t--){
    simulate();
}