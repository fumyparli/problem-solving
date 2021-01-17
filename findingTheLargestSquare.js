let a;
let d = [];
let m,
    n,
    ans = 0;

function foo(i, j) {
    if (i === m || j === n) {
        return 0;
    }
    if (d[i][j] !== -1) return d[i][j];
    let d1 = foo(i + 1, j);
    let d2 = foo(i, j + 1);
    let d3 = foo(i + 1, j + 1);
    if (a[i][j] && d1 && d2 && d3) {
        if (d1 === d2) d[i][j] = 1 + d3 + Math.sqrt(d3) * 2;
        else d[i][j] = 1 + Math.sqrt(Math.min(d1, d2)) * 2 + Math.min(d1, d2);
    } else {
        d[i][j] = a[i][j];
    }
    return d[i][j];
}

function solution(board) {
    a = board;
    m = board.length;
    n = board[0].length;
    for (let i = 0; i < m; i++) {
        d[i] = [];
        for (let j = 0; j < n; j++) {
            d[i].push(-1);
        }
    }
    foo(0, 0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (ans < d[i][j]) {
                ans = d[i][j];
            }
        }
    }
    return ans;
}
