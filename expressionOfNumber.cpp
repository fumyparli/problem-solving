using namespace std;

int solution(int n) {
    int answer = 1;
    int i = n / 2 + 1;
    int k = 2;
    while (true) {
        if (i - k < 0) break;
        if (i * (i + 1) - (i - k) * (i - k + 1) == 2 * n) {
            k++;
            answer++;
        }
        if (i * (i + 1) - (i - k) * (i - k + 1) < 2 * n) {
            k++;
            continue;
        }
        i--;
    }
    return answer;
}