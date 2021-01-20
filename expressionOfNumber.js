function solution(n) {
    let answer = 1;
    let i = Math.floor(n / 2) + 1;
    let k = 2;
    while (true) {
        if (i - k < 0) break;
        if (i * (i + 1) - (i - k) * (i - k + 1) === 2 * n) {
            k++;
            answer++;
        }
        if (i * (i + 1) - (i - k) * (i - k + 1) < 2 * n) {
            k++;
            continue;
        }
        i--;
    }
    return answer;
}
