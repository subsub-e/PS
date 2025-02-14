const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

let t = Number(input.shift());
let index = 0;
let uf;
let cnt;

function find(x){
    if(uf.get(x) === x){
        return x;
    }
    let root = find(uf.get(x)); 
    uf.set(x, root);
    return root;
}

function Union(x, y){
    let X = find(x);
    let Y = find(y);
    if (X !== Y) { 
        uf.set(Y, X);
        cnt.set(X, cnt.get(X) + cnt.get(Y));
    }
}

while(t--){
    uf = new Map();
    const n = Number(input[index++]);
    cnt = new Map();
    for(let i = 0; i < n; i++){
        let [str1, str2] = input[index++].split(' ');
        
        if (!uf.has(str1)) {
            uf.set(str1, str1);
            cnt.set(str1, 1);
        }
        if (!uf.has(str2)) {
            uf.set(str2, str2);
            cnt.set(str2, 1);
        }

        if (find(str1) !== find(str2)) {
            Union(str1, str2);
        }

        console.log(cnt.get(find(str1)));
    }
}