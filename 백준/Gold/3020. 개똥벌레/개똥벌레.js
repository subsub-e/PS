const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, h] = input.shift().split(' ').map(Number);

const bot = Array(500001).fill(0);
const to = Array(500001).fill(0);
const tot = Array(500001).fill(0);

const arr = input.map(Number);

for(let i = 0; i < n; i++){
    if(i % 2 == 0){
        bot[arr[i]]++;
    }
    else{
        to[arr[i]]++;
    }
}

for(let i = h; i > 0; i--){
    to[i - 1] += to[i];
    bot[i - 1] += bot[i];
}

for(let i = 1; i <= h; i++){
    tot[i] = to[i] + bot[h - i + 1];
}

let cnt = 0;
let min = 500001;

for(let i = 1; i <= h; i++){
    if(min > tot[i]){
        cnt = 1;
        min = tot[i];
    }
    else if(min === tot[i]){
        cnt++;
    }
}

console.log(min, cnt);
