const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

let s = [];
const n = Number(input.shift());
const arr = input[0].split(' ').map(Number);
let cnt = Array(1000001).fill(0);
let ans = [];

for(let i = 0; i < arr.length; i++){
    cnt[arr[i]]++;
}

for(let i = arr.length - 1; i >= 0; i--){
    while(s.length !== 0 && cnt[s[s.length - 1]] <= cnt[arr[i]]){
        s.pop();
    }
    if(s.length === 0){
        ans.push(-1);
    }
    else{
        ans.push(s[s.length - 1]);
    }
    s.push(arr[i]);
}

let answer = [];

for(let i = 0; i < ans.length; i++){
    answer.push(ans[ans.length - 1 - i]);
}


console.log(answer.join(' '));