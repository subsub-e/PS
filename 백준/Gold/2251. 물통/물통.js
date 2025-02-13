const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m, k] = input[0].split(' ').map(Number);

let visited = Array.from({length : n + 1}, () => Array.from({length : m + 1}, () => Array(k + 1).fill(false)));
let ansArr = Array(201).fill(0);

let q = [];
let index = 0;

visited[0][0][k] = 1;
q.push([0, 0, k]);
ansArr[k] = 1;

function cango(x, y, z){
    return 0 <= x && x <= n && 0 <= y && y <= m && 0 <= z && z <= k && !visited[x][y][z];
}

function bfs(){
    while(q.length > index){
        let [x, y, z] = q[index++];
        if(x === 0){
            ansArr[z] = 1;
        }

        if(x !== 0){
            let temp1 = m - y;
            let temp2 = k - z;
            if(cango(x - temp1, y + temp1, z)){
                q.push([x - temp1, y + temp1, z]);
                visited[x - temp1][y + temp1][z] = 1;
            }

            if(cango(x - temp2, y, z + temp2)){
                q.push([x - temp2, y, z + temp2]);
                visited[x - temp2][y][z + temp2] = 1;
            }

            if(cango(0, y + x, z)){
                q.push([0, y + x, z]);
                visited[0][y + x][z] = 1;
            }

            if(cango(0, y, z + x)){
                q.push([0, y, z + x]);
                visited[0][y][z + x] = 1;
            }
        }

        if(y !== 0){
            let temp1 = n - x;
            let temp2 = k - z;

            if(cango(x + temp1, y - temp1, z)){
                q.push([x + temp1, y - temp1, z]);
                visited[x + temp1][y - temp1][z] = 1;
            }

            if(cango(x, y - temp2, z + temp2)){
                q.push([x, y - temp2, z + temp2]);
                visited[x][y - temp2][z + temp2] = 1;
            }

            if(cango(x + y, 0, z)){
                q.push([x + y, 0, z]);
                visited[x + y][0][z] = 1;
            }

            if(cango(x, 0, z + y)){
                q.push([x, 0, z + y]);
                visited[x][0][z + y] = 1;
            }

        }

        if(z !== 0){
            let temp1 = n - x;
            let temp2 = m - y;

            if(cango(x + temp1, y, z - temp1)){
                q.push([x + temp1, y, z - temp1]);
                visited[x + temp1][y][z - temp1] = 1;
            }

            if(cango(x, y + temp2, z - temp2)){
                q.push([x, y + temp2, z - temp2]);
                visited[x][y + temp2][z - temp2] = 1;
            }

            if(cango(x + z, y, 0)){
                q.push([z + x, y, 0]);
                visited[x + z][y][0] = 1;
            }

            if(cango(x, y + z, 0)){
                q.push([x, y + z, 0]);
                visited[x][y + z][0] = 1;
            }

        }
    }
}


bfs();

let ans = [];
for(let i = 0; i <= 200; i++){
    if(ansArr[i]){
        ans.push(i);
    }
}

console.log(ans.join(' '));