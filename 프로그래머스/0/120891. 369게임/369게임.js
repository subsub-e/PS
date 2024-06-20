function solution(order) {
    str = String(order)
    const mapfn = (a) => parseInt(a);
    return str.split('').map(mapfn).reduce((sum, a) => {
        if(a == 3 || a == 6 || a == 9){
            sum++;
        }
        return sum;
    }, 0);
}