function solution(numbers, hand) {
    let answer = "";
    let lx = 3,
        ly = 0,
        rx = 3,
        ry = 2;
    for (let i = 0; i < numbers.length; i++) {
        if (numbers[i] === 0) {
            numbers[i] = 11;
        }
        numbers[i]--;
        let x = Math.floor(numbers[i] / 3);
        let y = numbers[i] % 3;
        let ldist = Math.abs(x - lx) + Math.abs(y - ly);
        let rdist = Math.abs(x - rx) + Math.abs(y - ry);
        let nb = numbers[i];
        if (nb === 0 || nb === 3 || nb === 6) {
            answer += "L";
            lx = x;
            ly = y;
        } else if (nb === 2 || nb === 5 || nb === 8) {
            answer += "R";
            rx = x;
            ry = y;
        } else {
            if (ldist < rdist) {
                answer += "L";
                lx = x;
                ly = y;
            } else if (ldist > rdist) {
                answer += "R";
                rx = x;
                ry = y;
            } else {
                if (hand === "left") {
                    answer += "L";
                    lx = x;
                    ly = y;
                } else {
                    answer += "R";
                    rx = x;
                    ry = y;
                }
            }
        }
    }
    return answer;
}
