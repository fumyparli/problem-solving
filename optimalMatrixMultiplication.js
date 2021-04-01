const solution = (a) => {
    let d = [];
    for (let i = 0; i < 201; i++) {
        d[i] = [];
        for (let j = 0; j < 201; j++) {
            d[i][j] = -1;
        }
    }
    const foo = (i, j) => {
        if (i == j) {
            return 0;
        }
        if (d[i][j] != -1) {
            return d[i][j];
        }
        d[i][j] = 2222222222;
        for (let k = i; k < j; k++) {
            d[i][j] = Math.min(
                d[i][j],
                foo(i, k) + foo(k + 1, j) + a[i][0] * a[k][1] * a[j][1]
            );
        }
        return d[i][j];
    };
    return foo(0, a.length - 1);
};
