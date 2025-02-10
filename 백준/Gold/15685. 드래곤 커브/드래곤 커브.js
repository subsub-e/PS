const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input.shift());

let visited = Array.from({length : 101}, () => Array(101).fill(0));
let dx = [0, -1, 0, 1];
let dy = [1, 0, -1, 0];


function solution(x, y, dir, level){
    const graph = [(dir + 1) % 4];
    visited[x][y] = 1;
    let nx = x + dx[dir];
    let ny = y + dy[dir];
    visited[nx][ny] = 1;
    for(let i = 0; i < level; i++){
        const graphSize = graph.length;
        for(let j = graphSize - 1; j >= 0; j--){
            nx += dx[graph[j]];
            ny += dy[graph[j]];
            visited[nx][ny] = 1;
            graph.push((graph[j] + 1) % 4);
        }
    }
}

for(let i = 0; i < n; i++){
    const [x, y, dir, level] = input[i].split(' ').map(Number);
    solution(y, x, dir, level);
}

let cnt = 0;
for(let i = 0; i < 100; i++){
    for(let j = 0; j < 100; j++){
        
        if(visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]){
            cnt++;
        }
    }
}

console.log(cnt);