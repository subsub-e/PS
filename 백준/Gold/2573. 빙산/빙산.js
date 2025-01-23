const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.shift().split(' ').map(Number);
let arr = Array.from({length : n});
for(let i = 0; i < n; i++){
    arr[i] = input[i].split(' ').map(Number);
}

let visited = Array.from({length : n}, () => Array.from({length : m}).fill(0));
let i = 1;
let dx = [-1, 0, 1, 0];
let dy = [0, -1, 0, 1];
let ice_cnt = 0;

function cango(x, y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

function melting(){
    let temp = Array.from({length : n}, () => Array.from({length : m}).fill(0));

    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(arr[i][j] > 0){
                let cnt = 0;
                for(let k = 0; k < 4; k++){
                    let nx = i + dx[k];
                    let ny = j + dy[k];
                    if(cango(nx, ny) && arr[nx][ny] === 0){
                        cnt++;
                    }
                }
                if(arr[i][j] - cnt < 0){
                    temp[i][j] = 0;
                }
                else{
                    temp[i][j] = arr[i][j] - cnt;
                }
            }
        }
    }

    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            arr[i][j] = temp[i][j];
        }
    }
    //console.log(arr);
}

function bfs(now_x, now_y){
    let queue = [];
    visited[now_x][now_y] = 1;
    let temp_i = 0;
    queue.push([now_x, now_y]);
    while(queue.length > temp_i){
        let [x, y] = queue[temp_i++];

        for(let i = 0; i < 4; i++){
            let nx = x + dx[i];
            let ny = y + dy[i];
            if(cango(nx, ny) && !visited[nx][ny] && arr[nx][ny] > 0){
                queue.push([nx, ny]);
                visited[nx][ny] = 1;
            }
        }
    }
}

function check(){
    ice_cnt = 0;
    visited = Array.from({length : n}, () => Array.from({length : m}).fill(0));
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(arr[i][j] > 0 && !visited[i][j]){
                ice_cnt++;
                bfs(i, j);
            }
        }
    } 
}

while(1){
    melting();
    check();
    if(ice_cnt > 1){
        console.log(i);
        break;
    }
    if(ice_cnt == 0){
        console.log(0);
        break;
    }
    i++
}

// console.log(arr);
// console.log(visited);

