const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, r, q] = input[0].split(' ').map(Number);

const graph = Array.from({length : n + 1}, () => []);
const dp = Array(n + 1).fill(0);
const visited = Array(n + 1).fill(false);

for(let i = 1; i < n; i++){
    const [u, v] = input[i].split(' ').map(Number);
    graph[u].push(v);
    graph[v].push(u);
}

function dfs(now){
    visited[now] = true;
    dp[now] = 1;

    for(const node of graph[now]){
        if(!visited[node]){
            dp[now] += dfs(node);
        }
    }

    return dp[now];
}

dfs(r);

for(let i = n; i < n + q; i++){
    const u = Number(input[i]);
    console.log(dp[u]);
}