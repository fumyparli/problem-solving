function solution(p, location) {
    for (let i = 0; i < p.length; i++) {
        p[i] = [p[i], i];
    }
    let toFind = p[location][1];
    let i = 0;
    while (true) {
        let flag = 0;
        let popped = p.shift();
        for (let j = 0; j < p.length; j++) {
            if (popped[0] < p[j][0]) {
                p.push(popped);
                flag = 1;
                break;
            }
        }
        if (flag === 0) {
            i++;
            if (popped[1] === toFind) return i;
        }
    }
}
