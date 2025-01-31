const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const n = Number(input[0]);
const graph = Array.from({length : n + 1}, () => []);
let parent = Array(n + 1).fill(-1);
let visited = Array(n + 1).fill(false);
const ans = Array.from({length : n + 1}, () => []);
let cnt = 1;
let maxans = 0;
let maxDepth = 1;
let parentNode = 0;

for(let i = 1; i <= n; i++){
    const [now, left, right] = input[i].split(' ').map(Number);
    graph[now].push(left, right);
    parent[left] = now;
    parent[right] = now;
}

for(let i = 1; i <= n; i++){
    if(parent[i] === -1){
        parentNode = i;
        break;
    }
}

function dfs(now, depth){
    visited[now] = 1;
    let [left, right] = graph[now];
    if(!visited[left] && left !== -1){
        dfs(left, depth + 1);
    }
    ans[depth].push(cnt++);
    if(!visited[right] && right !== -1){
        dfs(right, depth + 1);
    }
}

dfs(parentNode, 1);

for(let i = 1; i <= n; i++){
    if(ans.length >= 2){
        let first = ans[i][0];
        let second = ans[i][ans[i].length - 1];
        if(maxans < second - first){
            maxans = (second - first);
            maxDepth = i;
        }
    }
}

console.log(maxDepth);
console.log(maxans + 1);