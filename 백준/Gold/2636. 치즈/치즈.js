const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.shift().split(' ').map(Number);

let arr = Array.from({length : n});
let visited = Array.from({length : n}, () => Array(m).fill(0));
let temp = Array.from({length : n});
const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];
let cnt = 0;
let lastcnt = 0;
let nowCnt = 0;


for(let i = 0; i < n; i++){
    arr[i] = input[i].split(' ').map(Number); 
}


function bfs(){
    visited = Array.from({length : n}, () => Array(m).fill(0));
    temp = arr.map(row => [...row]);
    visited[0][0] = 1;
    let q = [];
    q.push([0, 0]);
    let index = 0;
    nowCnt = 0;
    while(q.length > index){
        let [x, y] = q[index++];

        for(let i = 0; i < 4; i++){
            let nx = x + dx[i];
            let ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]){
                if(arr[nx][ny] === 0){
                    visited[nx][ny] = 1;
                    //console.log(nx, ny, arr[nx][ny]);
                    q.push([nx, ny]);
                }
                else if(arr[nx][ny] === 1 && temp[nx][ny] === 1){
                    temp[nx][ny] = 0;
                    nowCnt++;
                }
            }
        }
    }
}

while(1){
    bfs();
    //console.log(temp);
    arr = temp.map(row => [...row]);
    if(nowCnt === 0){
        console.log(cnt);
        console.log(lastcnt);
        break;
    }
    lastcnt = nowCnt;
    cnt++;
}