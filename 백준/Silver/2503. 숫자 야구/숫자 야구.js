const [N, ...nums] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let res = [];

for(let i = 0; i < Number(N); i++) {
    findBaseBallCnt(nums[i]);
}
console.log(res.length);

function findBaseBallCnt(numInfo) {
    const [number, strike, ball] = numInfo.split(' ').map(Number);
    const resNumArr = [];
    
    for(let i = 1; i < 10; i++) {
        for(let j = 1; j < 10; j++) {
            for(let k = 1; k < 10; k++) {
                if(i === j || j === k || k === i) continue;
                
                const curr = String(i) + String(j) + String(k);
                const count = {strike: 0, ball: 0};
               
                for(let l = 0; l < String(number).length; l++) {
                    const idx = curr.indexOf(number.toString()[l]);
                    if(idx === l) count.strike += 1;
                    else if(idx !== -1) count.ball += 1;
                }
                
                if(strike === count.strike && ball === count.ball) resNumArr.push(curr);
            }
        }
    }
    if(res.length === 0) res = [...resNumArr];
    else res = resNumArr.filter(ele => res.includes(ele));
}