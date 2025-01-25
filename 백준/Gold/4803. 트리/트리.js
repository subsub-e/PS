const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

let index = 0;
let testCase = 1

function cycle(now, prev, visited, graph){
    visited[now] = 1;
    for(let y of graph[now]){
        if(!visited[y]){
            if(cycle(y, now, visited, graph)){
                return true;
            }
        }
        else if(y !== prev){
            return true;
        }
    }
    return false;
}

function solution(x, y){
    let visited = Array.from({length : x}, () => 0);
    let cnt = 0;
    let arr = Array.from({length : y});
    const graph = new Array(x + 1);
    for (let i = 1; i <= x; i += 1) graph[i] = [];

    for(let i = 0; i < y; i++){
        arr[i] = input[index++].split(' ').map(Number);
    }

    //console.log(arr);


    for(let i = 0; i < y; i++){
        const [x, y] = arr[i];
        //console.log(x, y);
        graph[x].push(y);
        graph[y].push(x);
    }

    for(let i = 1; i <= x; i++){
        if(!visited[i]){
            if(!cycle(i, 0, visited, graph)){
                cnt++;
            }
        }
    }
    
    if(cnt > 1){
        console.log(`Case ${testCase}: A forest of ${cnt} trees.`);
    }
    else if(cnt === 1){
        console.log(`Case ${testCase}: There is one tree.`);
    } else {
        console.log(`Case ${testCase}: No trees.`);
    }
    testCase += 1;
    
}

for(let i = 0; i < input.length; i++){
    let [n, m] = input[index++].split(' ').map(Number);
    if(n == 0){
        break;
    }
    solution(n, m);

}