function solution(n, w) {
    let m = new Map();
    m.set(w[0], 0);
    for (let i = 1; i < w.length; i++) {
        if (w[i - 1][w[i - 1].length - 1] === w[i][0] && !m.has(w[i])) {
            m.set(w[i], 0);
        } else {
            return [(i % n) + 1, Math.floor(i / n) + 1];
        }
    }
    return [0, 0];
}
