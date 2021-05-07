function solution(a) {
    let n = a.length;
    let check = [];
    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];
    for (let i = 0; i < 26; i++) {
        check[i] = [];
        for (let j = 0; j < 26; j++) {
            check[i][j] = 2000000000;
        }
    }
    let q = [[0, 0, -1, 0]];
    check[0][0] = 0;
    while (q.length !== 0) {
        let [x, y, dir, cost] = q[0];
        q.shift();
        for (let k = 0; k < 4; k++) {
            let nx = x + dx[k];
            let ny = y + dy[k];
            let ncost = cost + 100;
            if (dir !== -1 && dir !== k) {
                ncost += 500;
            }
            if (0 <= nx && nx < n && 0 <= ny && ny < n && a[nx][ny] === 0) {
                if (check[nx][ny] >= ncost) {
                    check[nx][ny] = ncost;
                    q.push([nx, ny, k, ncost]);
                }
            }
        }
    }
    return check[n - 1][n - 1];
}
