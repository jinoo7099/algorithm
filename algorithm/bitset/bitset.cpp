#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // bitset<6> bit; // "000000"
    // bitset<6> bit(52); // "110100"
    bitset<6> bit("110100");

    // 뒤에서 부터 인덱스 0 시작
    bit.reset(2);  // 뒤에서부터 index임 - 110'0'00
    bit.set(1);    // 1100'1'0

    if (bit.all()) {
        cout << "모두 1" << endl;
    }

    if (bit.any()) {
        cout << "1이 하나라도 존재하면 true" << endl;
    }

    if (bit.none()) {
        cout << "전부 0" << endl;
    }

    cout << bit << endl;

    // 10진수 -> 2진수 문자열
    int num = 52;
    bitset<8> bit2(num);
    string s = bit2.to_string();

    cout << bit2.count() << "1의 개수" << endl;
    cout << bit2.size() << "bit size" << endl;

    // 뒤에서부터 접근함!!!!!!!!!!!!!!!!
    for (int i = 0; i < bit2.size(); i++) {
        cout << bit2[i];
    }

    return 0;
}
