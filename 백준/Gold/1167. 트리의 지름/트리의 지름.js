const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input[0]);

const graph = Array.from({length : n + 1}, () => []);
let visited = Array(n + 1).fill(false);
let maxNode = 0;
let maxDist = 0;

for(let i = 1; i <= n; i++){
    const arr = input[i].split(' ').map(Number);

    let index = 1;
    while(1){
        if(arr[index] === -1){
            break;
        }
        graph[arr[0]].push([arr[index], arr[index + 1]]);
        index += 2;
    }
}

function dfs(now, dist){
    visited[now] = 1;

    if(dist > maxDist){
        maxDist = dist;
        maxNode = now;
    }
    for(const [nextNode, cost] of graph[now]){
        if(!visited[nextNode]){
            dfs(nextNode, dist + cost);
        }
    }
}

dfs(1, 0);

visited.fill(false);

dfs(maxNode, 0);

console.log(maxDist);