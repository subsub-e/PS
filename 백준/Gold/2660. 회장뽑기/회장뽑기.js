const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());
const INF = Number.MAX_VALUE;
let arr = Array.from({length : n + 1}, () => Array.from({length : n + 1}).fill(INF));

for(let i = 1; i <= n; i++){
    arr[i][i] = 0;
}

for(let i = 0; i < input.length; i++){
    let [x, y] = input[i].split(' ').map(Number);
    if(x == -1){
        break;
    }
    arr[x][y] = 1;
    arr[y][x] = 1; 
}

for(let k = 1; k <= n; k++){
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
        }
    }
}

let ans = Array.from({length : n + 1}).fill(-1);

let minans = INF;
for(let i = 1; i <= n; i++){
    let temp = 0;
    for(let j = 1; j <= n; j++){
        temp = Math.max(temp, arr[i][j]);
    }
    ans[i] = temp;
    minans = Math.min(minans, temp);
}

let ansArr = [];
for(let i = 1; i <= n; i++){
    if(minans === ans[i]){
        ansArr.push(i);
    }
}

console.log(minans, ansArr.length);
let str = "";
for(let i = 0; i < ansArr.length; i++){
    str += (ansArr[i] + ' ');
}
console.log(str.trim());


