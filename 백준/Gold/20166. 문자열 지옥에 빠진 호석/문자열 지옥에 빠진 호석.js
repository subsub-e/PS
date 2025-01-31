const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m, k] = input[0].split(' ').map(Number);

let arr = Array.from({length : n}, () => []);
const dx = [-1, 0, 1, 1, 1, 0, -1, -1];
const dy = [-1, -1, -1, 0, 1, 1, 1, 0];
let map = {};

for(let i = 1; i <= n; i++){
    arr[i-1] = input[i].split('');
}

function dfs(str, x, y, len){
    if(str.length === len){
        map[str] = (map[str] || 0) + 1;
        return;
    }

    for(let i = 0; i < 8; i++){
        let nx = (x + dx[i] + n) % n;
        let ny = (y + dy[i] + m) % m;
        dfs(str + arr[nx][ny], nx, ny, len);
    }
}


for(let i = 0; i < n; i++){
    for(let j = 0; j < m; j++){
        for(let k = 1; k <= 5; k++){
            dfs(arr[i][j], i, j, k);
        }
    }
}

for(let i = n + 1; i < k + n + 1; i++){
    console.log(map[input[i]] || 0);
}