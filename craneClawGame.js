function solution(board, moves) {
    var answer = 0;
    var stack = [];
    moves.forEach((e) => {
        for (var i = 0; i < board.length; i++) {
            if (board[i][e - 1] !== 0) {
                if (stack[stack.length - 1] === board[i][e - 1]) {
                    stack.pop();
                    answer += 2;
                } else {
                    stack.push(+board[i][e - 1]);
                }
                board[i][e - 1] = 0;
                break;
            }
        }
    });
    return answer;
}
