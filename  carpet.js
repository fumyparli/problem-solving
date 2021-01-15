function solution(b, y) {
    let n = 1;
    while (true) {
        if (n + (b + y) / n === (b + 4) / 2) break;
        n++;
    }
    let m = (b + y) / n;
    return [m, n];
}
