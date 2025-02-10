const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());
const arr = input.shift().split(' ').map(Number);
let visited = Array.from({length : n + 1}, () => Array(40001).fill(0));


function dfs(cnt, result){
    if(cnt > n){
        return;
    }
    if(visited[cnt][result]){
        return;
    }

    //console.log(cnt, result);

    visited[cnt][result] = 1;


    dfs(cnt + 1, result + arr[cnt]);
    dfs(cnt + 1, result);
    dfs(cnt + 1, Math.abs(result - arr[cnt]));
}


dfs(0, 0);


let ans = [];
let check = input[1].split(' ').map(Number);
for(let i = 0; i < check.length; i++){
    if(visited[n][check[i]]){
        ans.push('Y');
    }
    else{
        ans.push('N');
    }
}

console.log(ans.join(' '));