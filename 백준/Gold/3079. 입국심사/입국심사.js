const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.shift().split(' ').map(Number);

const arr = input.map(Number);

arr.sort((a, b) => a - b);

let min = BigInt(1);
let max = BigInt(arr[n - 1] * m);
let answer = max;

while(min <= max){
    let cnt = BigInt(0);
    let mid = BigInt((min + max) / BigInt(2));

    for(let i = 0; i < n; i++){
        cnt += mid / BigInt(arr[i]);
    }

    if(cnt >= m){
        answer = mid;
        max = mid - BigInt(1);
    }
    else{
        min = mid + BigInt(1);
    }
}

console.log(String(answer));