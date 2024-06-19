function solution(array) {
    let answer = [];
    const maxValue = array.reduce((a, b) => Math.max(a, b), -Infinity);
    const maxIndex = array.indexOf(maxValue);
    answer.push(maxValue);
    answer.push(maxIndex);
    return answer;
}