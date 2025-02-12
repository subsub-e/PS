const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m] = input.shift().split(' ').map(Number);
const arr = Array.from({length : n});
for(let i = 0; i < n; i++){
    arr[i] = input[i].split(' ').map(Number);
}
const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];
const INF = 1e9 + 10;
let visited = Array.from({length : n}, () => Array.from({length : m}, () => Array(4).fill(INF)));
let q = [];
let index = 0;
let [sx, sy, sdir] = input[n].split(' ').map(Number);
let [ex, ey, edir] = input[n + 1].split(' ').map(Number);


function check(dir){
    if(dir === 1){
        return 3;
    }
    if(dir === 2){
        return 1;
    }
    if(dir === 3){
        return 2;
    }
    return 0;
}

sdir = check(sdir);
edir = check(edir);

visited[sx - 1][sy - 1][sdir] = 0;
q.push([sx - 1, sy - 1, sdir]);

function cango(x, y){
    return 0 <= x && x < n && 0 <= y && y < m && arr[x][y] === 0;
}

function bfs(){
    while(q.length > index){
        let [x, y, dir] = q[index++];



        for(let i = 1; i <= 3; i++){
            let nx = x + i * dx[dir];
            let ny = y + i * dy[dir];
            if(!cango(nx, ny)){
                break;
            }
            if(visited[nx][ny][dir] > visited[x][y][dir] + 1){
                visited[nx][ny][dir] = visited[x][y][dir] + 1;
                q.push([nx, ny, dir]);
            }
        }

        if(visited[x][y][(dir + 1) % 4] > visited[x][y][dir] + 1){
            visited[x][y][(dir + 1) % 4] = visited[x][y][dir] + 1;
            q.push([x, y, (dir + 1) % 4]);
        }

        if(visited[x][y][(dir - 1 + 4) % 4] > visited[x][y][dir] + 1){
            visited[x][y][(dir - 1 + 4) % 4] = visited[x][y][dir] + 1;
            q.push([x, y, (dir - 1 + 4) % 4]);
        }
    }
}


bfs();

//console.log(visited);

console.log(visited[ex - 1][ey - 1][edir]);