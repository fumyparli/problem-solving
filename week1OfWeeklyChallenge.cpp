using namespace std;
using ll = long long;
ll solution(int price, int money, int count) {
    ll answer = (ll)price * count * (count + 1) / 2 - money;
    return answer > 0 ? answer : 0;
}