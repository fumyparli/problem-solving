const solution = (a) => {
    let answer = -1;
    let check = [];
    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];
    let n = a.length;
    let m = a[0].length;
    for (let i = 0; i < n; i++) {
        check[i] = [];
        for (let j = 0; j < m; j++) {
            check[i][j] = 0;
        }
    }
    let q = [];
    q.push([0, 0, 0]);
    check[0][0] = 1;
    while (q.length !== 0) {
        let r = q[0];
        q.shift();
        if (r[0] == n - 1 && r[1] == m - 1) {
            answer = r[2] + 1;
            break;
        }
        for (let k = 0; k < 4; k++) {
            let nx = r[0] + dx[k];
            let ny = r[1] + dy[k];
            if (
                0 <= nx &&
                nx < n &&
                0 <= ny &&
                ny < m &&
                check[nx][ny] == 0 &&
                a[nx][ny] == 1
            ) {
                check[nx][ny] = 1;
                q.push([nx, ny, r[2] + 1]);
            }
        }
    }
    return answer;
};
