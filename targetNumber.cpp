#include <string>
#include <vector>
using namespace std;

vector<int> v;
int t;
int answer;

void foo(int x, int i) {
    if (v.size() == i) {
        if (x == t) {
            answer++;
        }
        return;
    }
    foo(x - v[i], i + 1);
    foo(x + v[i], i + 1);
}

int solution(vector<int> numbers, int target) {
    v = numbers;
    t = target;
    foo(0, 0);
    return answer;
}