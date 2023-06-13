#include <iostream>

using namespace std;

// 문자열을 복사하는 함수
void mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 두 문자열을 비교하는 함수
/*
    기존 strcmp
    - str1 < str2인 경우 음수 반환 - AAB vs AAC
    - str1 > str2인 경우 양수 반환 - AAC vs AAA
    - str1 == str2인 경우 0 반환 - AAA vs AAA

*/
int mystrcmp(const char* a, const char* b) {
    while (*a && *a == *b) ++a, ++b;
    return *a - *b;
}

int main() {
    char str1[20];
    char str2[20] = "Hello, world!";
    char str3[20] = "A";
    char str4[20] = "AB";
    // strcpy 테스트
    mystrcpy(str1, str2);
    std::cout << "str1: " << str1 << std::endl;

    // strcmp 테스트
    int result = mystrcmp(str1, str2);
    if (result == 0)
        std::cout << "str1과 str2는 같습니다." << std::endl;
    else if (result < 0)
        std::cout << "str1은 str2보다 작습니다." << std::endl;
    else
        std::cout << "str1은 str2보다 큽니다." << std::endl;

    cout << mystrcmp(str3, str4) << endl;

    return 0;
}
