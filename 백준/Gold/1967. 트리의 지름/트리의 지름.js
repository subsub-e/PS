const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


let n = Number(input[0]);
let maxans = 0;
let maxNode = 0;
let maxDist = 0;

const graph = Array.from({length : n + 1}, () => []);

for(let i = 1; i < n; i++){
    const [u, v, cost] = input[i].split(' ').map(Number);
    graph[u].push([v, cost]);
    graph[v].push([u, cost]);
}

let visited = Array(n + 1).fill(false);

function dfs(now, cost){
    visited[now] = 1;

    if(maxDist < cost){
        maxNode = now;
        maxDist = cost;
    }

    for(let [next, nowCost] of graph[now]){
        if(!visited[next]){
            dfs(next, cost + nowCost);
        }
    }
}

dfs(1, 0);
visited.fill(false);
dfs(maxNode, 0);
console.log(maxDist);