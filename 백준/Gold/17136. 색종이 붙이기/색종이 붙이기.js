const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")

let arr = Array.from({length : 10});
for(let i = 0; i < 10; i++){
    arr[i] = input[i].split(' ').map(Number);
}
let paperCnt = Array(6).fill(5);

let ans = Infinity;

function cango(x, y){
    return 0 <= x && x < 10 && 0 <= y && y < 10 && arr[x][y] === 1;
}

function find(x, y, siz){
    for(let i = x; i < x + siz; i++){
        for(let j = y; j < y + siz; j++){
            if(!cango(i, j)){
                return false;
            }
        }
    }
    return true
}


function setPaper(x, y, siz, target){
    for(let i = x; i < x + siz; i++){
        for(let j = y; j < y + siz; j++){
            arr[i][j] = target;
        }
    }
}

function dfs(idx, cnt){
    if(idx >= 100){
        ans = Math.min(ans, cnt);
        return;
    }
    if(ans <= cnt){
        return;
    }

    const x = Math.floor(idx / 10);
    const y = idx % 10;

    if(arr[x][y] === 1){
        for(let i = 5; i > 0; i--){
            if(!find(x, y, i) || paperCnt[i] === 0){
                continue;
            }
            paperCnt[i]--;
            setPaper(x, y, i, 0);
            dfs(idx + 1, cnt + 1);
            setPaper(x, y, i, 1);
            paperCnt[i]++;
        }
    }
    else{
        dfs(idx + 1, cnt);
    }
}   


dfs(0, 0);


if(ans === Infinity){
    console.log(-1);
}
else{
    console.log(ans);
}