#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if ((reserve[i] > 0 && lost[j] > 0) && (reserve[i] == lost[j])) {
                reserve[i] = -1;
                lost[j] = -1;
                answer++;
            }
        }
    }
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] > 0 && lost[j] > 0 && (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j])) {
                reserve[i] = -1;
                lost[j] = -1;
                answer++;
            }
        }
    }
    return answer;
}