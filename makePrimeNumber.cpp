#include <vector>
using namespace std;

int check[3001];
vector<int> v;
int answer;

int era(int num) {
    if (check[num] == 0) return 1;
    return 0;
}

void foo(int x, vector<int> &n) {
    if (v.size() == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += v[i];
        }
        answer += era(sum);
        return;
    }
    for (int i = x; i < n.size(); i++) {
        v.push_back(n[i]);
        foo(i + 1, n);
        v.pop_back();
    }
}

int solution(vector<int> nums) {
    check[1] = 1;
    for (int i = 2; i * i < 3001; i++) {
        if (check[i] == 0) {
            for (int j = i + i; j < 3001; j += i) {
                if (check[j] == 0) check[j] = 1;
            }
        }
    }
    foo(0, nums);
    return answer;
}