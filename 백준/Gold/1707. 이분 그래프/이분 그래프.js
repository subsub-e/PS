const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

let t = Number(input.shift());
let index = 0;

function bfs(x, graph, visited){
    let queue = [];
    visited[x] = 1;
    queue.push(x);

    let idx = 0;
    while(queue.length > idx){
        let cur = queue[idx++];
        
        for(let i = 0; i < graph[cur].length; i++){
            let next = graph[cur][i];
            if(!visited[next]){
                if(visited[cur] === 1){
                    visited[next] = 2;
                }
                else{
                    visited[next] = 1;
                }
                queue.push(next);
            }
        }
    }
}

function solution(){
    const [n, m] = input[index++].split(' ').map(Number);

    let graph = Array.from({ length: n + 1 }, () => []);
    let visited = Array.from({ length: n + 1 }, () => 0);

    for(let i = 0; i < m; i++){
        const [from, to] = input[index++].split(' ').map(Number);
        graph[from].push(to);
        graph[to].push(from);
    }

    for(let i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(i, graph, visited);
        }
    }

    for(let i = 1; i <= n; i++){
        for(let j = 0; j < graph[i].length; j++){
            let next = graph[i][j];
            if(visited[i] === visited[next]){
                console.log("NO");
                return;
            }
        }
    }
    console.log("YES");
}

while(t--){
    solution();
}