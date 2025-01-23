const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const [n, m] = input.shift().split(' ').map(Number);

const arr = input[0].split(' ');

arr.sort((a, b) => {
    if(a > b) return 1;
    if(a < b) return -1;
});

let answer = [];
let visited = Array.from({length : 27}).fill(0);

function check(str){
    let cnt = 0;
    let cnt1 = 0;
    for(let i = 0; i < n; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            cnt++;
        }
        else{
            cnt1++;
        }
    }
    if(cnt >= 1 && cnt1 >= 2){
        return true;
    }
    else{
        return false;
    }
}

function dfs(now, str){
    if(str.length == n){
        //console.log(str);
        if(check(str)){
            const pp = str.reduce((an, no) => an + no, "");
            answer.push(pp);
        }
        return;
    }

    for(let i = now; i < arr.length; i++){
        if(!visited[arr[i].charCodeAt() - 97]){
            visited[arr[i].charCodeAt() - 97] = 1;
            str.push(arr[i]);
            dfs(i + 1, str);
            str.pop();
            visited[arr[i].charCodeAt() - 97] = 0;
        }
    }
}

dfs(0, []);

answer.forEach(element => {
    console.log(element);
});