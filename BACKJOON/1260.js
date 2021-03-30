// stdin //
const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
// stdin //
let nmv = input[0].split(" ");
let n = +nmv[0];
let m = +nmv[1];
let st = +nmv[2];
let a = [];
let check = new Array(1001);
check.fill(0);
for (let i = 0; i < 1001; i++) {
    a[i] = [];
}
for (let i = 0; i < m; i++) {
    let s = input[i + 1].split(" ");
    a[s[0]].push(s[1]);
    a[s[1]].push(s[0]);
}
for (let i = 0; i < a.length; i++) {
    a[i].sort((a, b) => a - b);
}
let dfs = (x) => {
    check[x] = 1;
    process.stdout.write(x + " ");
    a[x].forEach((nx) => {
        if (check[nx] === 0) {
            dfs(nx);
        }
    });
};
dfs(st);
console.log();
let q = [+st];
check.fill(0);
check[st] = 1;
while (q.length !== 0) {
    let x = q[0];
    q.shift();
    process.stdout.write(x + " ");
    a[x].forEach((nx) => {
        if (check[nx] === 0) {
            check[nx] = 1;
            q.push(nx);
        }
    });
}
