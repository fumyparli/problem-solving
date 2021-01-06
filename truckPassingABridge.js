function solution(length, weight, t) {
    let i = 1;
    let sum = 0;
    let q = [];
    while (true) {
        if (q.length > 0 && q[0][1] === i) {
            sum -= q[0][0];
            q.shift();
        }
        if (sum + t[0] <= weight) {
            sum += t[0];
            q.push([t[0], i + length]);
            t.shift();
        }
        if (t.length === 0 && q.length === 0) break;
        i++;
    }
    return i;
}
