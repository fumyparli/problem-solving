let n, m;
let bt = [];
let check = [];
let user, banned;
let ma = {};
let ans = 0;
function foo() {
    if (bt.length === m) {
        let tmp = [...bt];
        tmp.sort();
        let str = "";
        for (let i = 0; i < m; i++) {
            str += tmp[i];
        }
        if (ma[str] === undefined) {
            let flag = 0;
            for (let i = 0; i < m; i++) {
                if (user[bt[i]].length !== banned[i].length) {
                    flag = 1;
                    break;
                }
                for (let j = 0; j < m; j++) {
                    if (
                        !(
                            banned[i][j] === "*" ||
                            user[bt[i]][j] === banned[i][j]
                        )
                    ) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag === 0) {
                ma[str] = 1;
                ans++;
            }
        }
        return;
    }
    for (let i = 0; i < n; i++) {
        if (check[i] === undefined) {
            check[i] = 1;
            bt.push(i);
            foo();
            bt.pop();
            check[i] = undefined;
        }
    }
}

function solution(user_id, banned_id) {
    n = user_id.length;
    m = banned_id.length;
    user = user_id;
    banned = banned_id;
    foo();
    return ans;
}
