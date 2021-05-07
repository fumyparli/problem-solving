function solution(stones, k) {
    let st = 0,
        ed = 200000000;
    while (true) {
        if (st >= ed) break;
        let mid = Math.floor((st + ed) / 2);
        let cnt = 0,
            maxv = 0;
        for (let i = 0; i < stones.length; i++) {
            if (stones[i] - mid <= 0) {
                cnt++;
                maxv = Math.max(maxv, cnt);
            } else {
                cnt = 0;
            }
        }
        if (maxv >= k) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    return ed;
}
