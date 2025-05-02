const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const t = Number(input[0]);
let n, home, arr, des;
let idx = 1;

let index = 0;

function bfs(n){
    let visited = Array(101).fill(0);
    let queue = [];
    queue.push(home);

    while(queue.length > index){
        let [x, y] = queue[index++];
        
        if(Math.abs(des[0] - x) + Math.abs(des[1] - y) <= 1000){
            return true;
        }
        for(let i = 0; i < n; i++){
            if(!visited[i] && (Math.abs(arr[i][0] - x) + Math.abs(arr[i][1] - y)) <= 1000){
                visited[i] = 1;
                queue.push(arr[i]);
            }
        }
    }

    return false;
}


for(let i = 0; i < t; i++){
    n = Number(input[idx++]);
    home = input[idx++].split(' ').map(Number);
    arr = [];
    index = 0;
    for(let j = 0; j < n; j++){
        arr.push(input[idx++].split(' ').map(Number));
    }
    des = input[idx++].split(' ').map(Number);

    if(bfs(n)){
        console.log("happy");
    }
    else{
        console.log("sad");
    }
}