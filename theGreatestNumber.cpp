#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    if (s1 > s2)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0) return "0";
    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);
    return answer;
}