function solution(a, b) {
    if (a > b) {
        let tmp = a;
        a = b;
        b = tmp;
    }
    let h = a;
    let w = b;
    for (let i = 1; i <= b; i++)
        if ((i * b) % a === 0) {
            b = (w * i) / a;
            a = a / (w / b);
            break;
        }
    return h * w - (Math.floor(b / a + 1) * a + (b % a) - 1) * (w / b);
}
