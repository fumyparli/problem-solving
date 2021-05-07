function solution(gems) {
    let answer = [];
    let g = {};
    let n = 0;
    for (let i = 0; i < gems.length; i++) {
        if (g[gems[i]] === undefined) {
            g[gems[i]] = 0;
            n++;
        }
    }
    let st = 0,
        ed = 0;
    let cnt = 0;
    let ans = 1000000;
    while (true) {
        if (g[gems[ed]] === 0) cnt++;
        g[gems[ed++]]++;
        if (cnt === n) {
            if (ans > ed - st) {
                ans = ed - st;
                answer = [st, ed];
            }
            while (true) {
                g[gems[st]]--;
                if (g[gems[st]] === 0) {
                    cnt--;
                    st++;
                    break;
                }
                st++;
                if (ans > ed - st) {
                    ans = ed - st;
                    answer = [st, ed];
                }
            }
        }
        if (ed === gems.length) break;
    }
    answer[0]++;
    return answer;
}
