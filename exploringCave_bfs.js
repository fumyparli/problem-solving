let haveToGo = [];
let rrel = [];
let a = [];
for (let i = 0; i < 200001; i++) {
    a[i] = [];
}
let check = [];

function solution(n, path, order) {
    for (let i = 0; i < path.length; i++) {
        a[path[i][0]].push(path[i][1]);
        a[path[i][1]].push(path[i][0]);
    }
    for (let i = 0; i < order.length; i++) {
        rrel[order[i][1]] = order[i][0];
        if (order[i][1] === 0) {
            return false;
        }
    }
    let q = [];
    q.push(0);
    check[0] = 1;
    while (q.length !== 0) {
        let x = q[0];
        q.shift();
        if (haveToGo[x]) {
            check[haveToGo[x]] = 1;
            q.push(haveToGo[x]);
        }
        for (let i = 0; i < a[x].length; i++) {
            let nx = a[x][i];
            if (rrel[nx] !== undefined && check[rrel[nx]] === undefined) {
                haveToGo[rrel[nx]] = nx;
                continue;
            }
            if (check[nx] === undefined) {
                check[nx] = 1;
                q.push(nx);
            }
        }
    }
    for (let i = 0; i < n; i++) {
        if (check[i] === undefined) {
            return false;
        }
    }
    return true;
}
