function solution(my_string) {
    const answer = my_string.toLowerCase().split('');
    answer.sort();
    return answer.join('');
}