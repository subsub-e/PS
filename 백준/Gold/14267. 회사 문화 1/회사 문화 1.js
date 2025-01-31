const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m] = input[0].split(' ').map(Number);
const graph = Array.from({length : n + 1}, () => []);
let sum = Array(n + 1).fill(0);
const arr = input[1].split(' ').map(Number);

for(let i = 2; i <= n; i++){
    graph[arr[i-1]].push(i);
}

for(let i = 2; i < 2 + m; i++){
    const [node, cost] = input[i].split(' ').map(Number);
    sum[node] += cost;
}

function dfs(now){
    for(const next of graph[now]){
        sum[next] += sum[now];
        dfs(next);
    }
}

dfs(1);

console.log(sum.slice(1).join(' '));