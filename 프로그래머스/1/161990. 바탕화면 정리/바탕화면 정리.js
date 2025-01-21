function solution(wallpaper) {

    let min_x = 10000;
    let min_y = 10000;
    let max_x = 0;
    let max_y = 0;
    
    for(let i = 0; i < wallpaper.length; i++){
        for(let j = 0; j < wallpaper[i].length; j++){
            if(wallpaper[i][j] == '#'){
                min_x = Math.min(min_x, i);
                min_y = Math.min(min_y, j);
                max_x = Math.max(max_x, i);
                max_y = Math.max(max_y, j);
            }
        }
    }
    return [min_x, min_y, max_x + 1, max_y + 1];
}