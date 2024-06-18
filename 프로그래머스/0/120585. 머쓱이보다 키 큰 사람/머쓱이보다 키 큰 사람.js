function solution(array, height) {
    let answer = 0;
    answer = array.filter(a => a > height).length;
    return answer;
}