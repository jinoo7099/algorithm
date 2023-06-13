#include <iostream>

using namespace std;

bool p[1000003];
int n = 1000000;
int main() {
    for (int i = 2; i * i <= n; i++) {
        if (p[i] == true) continue;

        for (int j = i + i; j <= n; j += i) {
            p[j] = true;
        }
    }

    for (int i = 2; i <= 30; i++) {
        if (p[i] == false) {
            cout << i << endl;
        }
    }

    return 0;
}