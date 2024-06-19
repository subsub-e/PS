function solution(num, k) {
    const temp = String(num).split('');
    if(temp.indexOf(String(k)) == -1){
        return -1;
    }
    return temp.indexOf(String(k)) + 1;
}