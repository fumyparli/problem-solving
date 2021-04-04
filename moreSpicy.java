import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < scoville.length; i++) {
            pq.add(scoville[i]);
        }
        int cnt = 0;
        while (true) {
            Integer pick1 = pq.peek();
            if (pick1 >= K) {
                return cnt;
            }
            pq.poll();
            if (pq.size() == 0)
                break;
            Integer pick2 = pq.peek();
            pq.poll();
            pq.add(pick1 + 2 * pick2);
            cnt++;
        }
        return -1;
    }
}