function solution(n) {
    let d = [];
    d[0] = 0;
    d[1] = 1;
    for (let i = 0; i < n - 1; i++) {
        d[i + 2] = (d[i] + d[i + 1]) % 1234567;
    }
    return d[n];
}
