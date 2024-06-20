function solution(before, after) {
    const arr = before.split('').sort().join('');
    const arr2 = after.split('').sort().join('');
    if(arr === arr2){
        return 1;
    }
    return 0;
}