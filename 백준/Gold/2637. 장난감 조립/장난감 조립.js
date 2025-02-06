const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());
const m = Number(input.shift());

let dp = Array.from({length : n + 1}, () => Array(n + 1).fill(0));
const graph = Array.from({length : n + 1}, () => []);
let indig = Array(n + 1).fill(0);
let q = [];
let result = [];

indig[n] = 1e9 + 10;

for(let i = 0; i < m; i++){
    const [x, p1, cnt] = input[i].split(' ').map(Number);
    graph[p1].push(x);
    dp[x][p1] += cnt;
    indig[x]++;
}


for(let i = 1; i <= n; i++){
    if(indig[i] === 0){
        q.push(i);
        result.push(i);
    }
}


let index = 0;
while(q.length > index){
    let now = q[index++];

    for(const next of graph[now]){
        for(let i = 1; i < n; i++){
            dp[next][i] += (dp[now][i] * dp[next][now]);
        }
        indig[next]--;
        if(indig[next]===0){
            q.push(next);
        }
    }
}

result.sort((a, b) => a - b);


for(let i = 0; i < result.length; i++){
    console.log(result[i], dp[n][result[i]]);
}