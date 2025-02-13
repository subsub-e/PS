const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input.shift());

const arr = input.map(Number);

let dp = Array(n + 1).fill(1);

for(let i = 1; i < n; i++){
    let cnt = 0;
    for(let j = 0; j < i; j++){
        if(arr[j] < arr[i]){
            cnt = Math.max(cnt, dp[j]);
        }
    }
    dp[i] = cnt + 1;
}


console.log(n - Math.max(...dp));