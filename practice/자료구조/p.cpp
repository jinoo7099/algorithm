#include <iostream>

using namespace std;

struct A {
    int a;

    void p() {
        cout << "Hello" << endl;
        cout << a << endl;
    }
};

int main() {
    A a;
    a.a = 10;
    a.p();
    return 0;
}