function solution(n, a, b) {
    let answer = 1;
    if (a > b) [a, b] = [b, a];
    while (true) {
        if (b - a === 1 && b % 2 === 0) break;
        a = Math.ceil(a / 2);
        b = Math.ceil(b / 2);
        answer++;
    }
    return answer;
}
