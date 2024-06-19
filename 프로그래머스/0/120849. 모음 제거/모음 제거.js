function solution(my_string) {
    let answer = my_string.replaceAll('u', '');
    answer = answer.replaceAll('a', '');
    answer = answer.replaceAll('o', '');
    answer = answer.replaceAll('i', '');
    answer = answer.replaceAll('e', '');
    return answer;
}