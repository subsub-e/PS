const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m, cost] = input.shift().split(' ').map(Number);

const arr = input.shift().split(' ').map(Number);
arr.unshift(0);

const graph = Array.from({length : n + 1}, () => []);

let uf = [];

for(let i = 0; i < m; i++){
    const [x, y] = input[i].split(' ').map(Number);

    graph[x].push(y);
    graph[y].push(x);
}

for(let i = 1; i <= n; i++){
    uf[i] = i;
}

function find(x){
    if(uf[x] === x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

function Union(x, y){
    let X = find(x);
    let Y = find(y);

    if(arr[X] < arr[Y]){
        uf[Y] = X;
    }
    else{
        uf[X] = Y;
    }
}

let now_cost = 0;

for(let i = 0; i < graph.length; i++){
    for(let j = 0; j < graph[i].length; j++){
        //console.log(i, graph[i][j]);
        Union(i, graph[i][j]);
    }
}


for(let i = 1; i <= n; i++){
    if(i == uf[i]){
        now_cost += arr[i];
    }
}


if(cost < now_cost){
    console.log("Oh no");
}
else{
    console.log(now_cost);
}