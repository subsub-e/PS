function solution(num_list) {
    let answer = [];
    const a = num_list.reduce((sum, a) => sum + a % 2, 0);
    const b = num_list.reduce((sum, a) => sum + !(a%2), 0);
    answer.push(b);
    answer.push(a);
    return answer;
}