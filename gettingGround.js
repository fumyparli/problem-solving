function solution(a) {
    // logic 똑같은데 c++은 되고 javascript로 효율성테스트 런타임에러뜸,,,,
    let answer = 0;
    let d = [];
    for (let i = 0; i < a.length; i++) {
        d.push([]);
    }

    function foo(i, j) {
        if (i === -1) return 0;
        if (d[i][j]) {
            return d[i][j];
        }
        let max = 0;
        for (let k = 0; k < 4; k++) {
            let foo_max = 0;
            if (k !== j) {
                foo_max = foo(i - 1, k);
                if (max < foo_max) {
                    max = foo_max;
                }
            }
        }
        d[i][j] = max + a[i][j];
        return d[i][j];
    }

    for (let i = 0; i < 4; i++) {
        foo(a.length - 1, i);
    }

    for (let i = 0; i < 4; i++) {
        if (answer < d[a.length - 1][i]) answer = d[a.length - 1][i];
    }
    return answer;
}
