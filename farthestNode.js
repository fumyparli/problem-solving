function solution(n, edge) {
    let a = [];
    let check = [];
    for (let i = 0; i <= n; i++) {
        a[i] = [];
        check[i] = -1;
    }
    for (let i = 0; i < edge.length; i++) {
        a[edge[i][0]].push(edge[i][1]);
        a[edge[i][1]].push(edge[i][0]);
    }
    let q = [1];
    check[1] = 0;
    let maxv = -1;
    let cnt = 1;
    while (q.length != 0) {
        let x = q[0];
        q.shift();
        if (maxv == check[x]) {
            cnt++;
        }
        if (maxv < check[x]) {
            maxv = check[x];
            cnt = 1;
        }
        for (let i = 0; i < a[x].length; i++) {
            let nx = a[x][i];
            if (check[nx] == -1) {
                check[nx] = check[x] + 1;
                q.push(nx);
            }
        }
    }
    return cnt;
}
