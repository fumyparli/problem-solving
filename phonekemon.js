function solution(nums) {
    var answer = 1;
    nums.sort((a, b) => a - b);
    let k = nums[0];
    for (let i = 0; i < nums.length; i++) {
        if (answer === nums.length / 2) break;
        if (k !== nums[i]) {
            k = nums[i];
            answer++;
        }
    }
    return answer;
}
