const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const [n, m] = input.shift().split(' ').map(Number);
let uf = Array.from({length : n + 1}).map((_, index) => index);
let graph = Array.from({length : m}, () => []);

function find(x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

function Union(x, y){
    let X = find(x);
    let Y = find(y);
    if(X != Y){
        uf[Y] = X;
    }
}

let tempArr = input.shift().split(' ').map(Number);

for(let i = 1; i < tempArr.length; i++){
    Union(0, tempArr[i]);
}


//console.log(uf);

for(let i = 0; i < m; i++){
    let arr = input[i].split(' ').map(Number);
    for(let j = 2; j < arr.length; j++){
        //console.log(arr[1], arr[j]);
        Union(arr[j - 1],arr[j]);
    }
}

//console.log(uf);

let ans = 0;

for(let i = 0; i < m; i++){
    let arr = input[i].split(' ').map(Number);
    let flag = 0;
    for(let j = 1; j < arr.length; j++){
        if(find(0) == find(arr[j])){
            flag = 1;
            break;
        }
    }
    if(flag === 0){
        ans++;
    }
}

console.log(ans);