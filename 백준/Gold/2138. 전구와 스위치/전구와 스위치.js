const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");


const n = Number(input.shift());
const str = input.shift();
const tar = input.shift();

function change(now){
    if(now === '0'){
        return '1';
    }
    else{
        return '0';
    }
}

function check(originStr, cnt){
    let nowStr = originStr.split('');
    let nowCnt = cnt;
    for(let i = 1; i < nowStr.length - 1; i++){
        if(nowStr[i-1] !== tar[i-1]){
            nowStr[i-1] = tar[i-1];
            nowStr[i] = change(nowStr[i]);
            nowStr[i + 1] = change(nowStr[i + 1]);
            nowCnt++;
        }
        //console.log(nowStr);
    }

    if(nowStr[nowStr.length - 2] !== tar[nowStr.length - 2]){
        nowStr[nowStr.length - 2] = tar[nowStr.length - 2];
        nowStr[nowStr.length - 1] = change(nowStr[nowStr.length - 1]);
        nowCnt++;
    }
    //console.log(nowStr);

    if(tar !== nowStr.join('')){
        return 1e9;
    }
    else{
        return nowCnt;
    }
}

function solution(nowStr, isCheck){
    let cnt1 = 0;
    let cnt2 = 0;
    if(isCheck){
        let temp = nowStr.slice(0, 2);
        let f = String(Math.abs(Number(temp[0]) - 1));
        let s = String(Math.abs(Number(temp[1]) - 1));

        let nextStr = f + s + nowStr.slice(2);
        cnt1 = check(nextStr, 1);
        return cnt1;
    }
    else{
        cnt2 = check(nowStr, 0);
        return cnt2;
    }
}


const answer = Math.min(solution(str, 0), solution(str, 1));

if(answer === 1e9){
    console.log(-1);
}
else{
    console.log(answer);
}