#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> ret;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        ret.push_back(temp);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

/**
 *
 * stream
 * c++ 프로그램은 파일이나 콘솔의 입출력을 직접 다루지 않고
 * 스트림을 통해 다룬다.
 *
 * 스트림은 운영체제가 입력과 출력을 다루기 위해 가상으로 만들어 준 것으로 중간 역할을 함
 *
 * buffer
 * 스트림 내부에 버퍼라는 임시 메모리 공간을 가진다.
 * 버퍼를 이용하면 프로그램의 입출력을 효율적으로 처리 가능
 *
 * 버퍼가 없으면 매번 키보드 입력이 프로그램으로 전송됨
 * 버퍼가 있으면 키보드 입력을 버퍼에 한번에 모아서 전송함
 *
 * stringstream
 * 문자열에서 동작하는 스트림(=외부에서 입출력으로 받은 것이 아니고 문자열로 초기화 시켜준것)
 *
 */

/*
int main() {
    int num; // 뽑아내고자 하는 자료형
    string str = "123 456 789";
    stringstream ss(str);

    while(stream >> num) {
        cout << num << ', ' << endl;
    }

    // 123, 456, 789
}
*/