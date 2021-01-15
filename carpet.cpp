#include <string>
#include <vector>
using namespace std;

vector<int> solution(int b, int y) {
    vector<int> answer;
    int n = 0;
    while (++n)
        if ((b + y) % n == 0 && n + (b + y) / n == (b + 4) / 2) break;
    answer.push_back((b + y) / n);
    answer.push_back(n);
    return answer;
}