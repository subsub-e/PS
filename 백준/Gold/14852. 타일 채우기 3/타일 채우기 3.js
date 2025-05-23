const input = require("fs").readFileSync("/dev/stdin").toString().trim();
const N = Number(input);

function solution(n){
    if(n === 1)
        return 2;
    else if(n === 2)
        return 7;
    let dp = new Array(n+1).fill(0n);
    const max = 1000000007n;
    dp[1] = 2n;
    dp[2] = 7n;
    dp[3] = 22n;
    for(let i = 4; i <= n; i++) {
        dp[i] = ((max + 3n * dp[i - 1]) - dp[i - 3] + dp[i - 2])%max;
	}
	return Number(dp[n]%max);
}

console.log(solution(N));