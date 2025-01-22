const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input[0]);
input.shift();

let arr = new Array(n);
for(let i = 0; i < n; i++){
    arr[i] = input[i].split('');
}

let cnt1 = 0;
let cnt2 = 0;

let check = new Array(n);
for(let i = 0; i < n; i++){
    check[i] = new Array(n).fill(0);
}

function bfs(x, y, color){
    let queue = [];
    queue.push([x, y]);
    check[x][y] = 1;
    let dx = [-1, 0, 1, 0];
    let dy = [0, -1, 0, 1];

    while(queue.length){
        let t = queue.shift();
        for(let i = 0; i < 4; i++){
            let nx = t[0] + dx[i];
            let ny = t[1] + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n && !check[nx][ny] && color == arr[nx][ny]){
                check[nx][ny] = 1;
                queue.push([nx, ny]);
            }
        }
    }
}

for(let i = 0; i < n; i++){
    for(let j = 0; j < n; j++){
        if(!check[i][j]){
            bfs(i, j, arr[i][j]);
            cnt1++;
        }
    }
}

for(let i = 0; i < n; i++){
    for(let j = 0; j < n; j++){
        if(arr[i][j] === 'G' || arr[i][j] === 'R'){
            arr[i][j] = '#';
        }
    }
}

check = new Array(n);
for(let i = 0; i < n; i++){
    check[i] = new Array(n).fill(0);
}

for(let i = 0; i < n; i++){
    for(let j = 0; j < n; j++){
        if(!check[i][j]){
            bfs(i, j, arr[i][j]);
            cnt2++;
        }
    }
}

console.log(cnt1, cnt2);
