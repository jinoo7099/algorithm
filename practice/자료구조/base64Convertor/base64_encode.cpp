#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string base64_encode(const std::string& input) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string encoded;
    size_t input_length = input.length();

    for (size_t i = 0; i < input_length; i += 3) {
        unsigned char char1 = input[i];
        unsigned char char2 = (i + 1 < input_length) ? input[i + 1] : 0;
        unsigned char char3 = (i + 2 < input_length) ? input[i + 2] : 0;

        unsigned char index1 = char1 >> 2;
        unsigned char index2 = ((char1 & 3) << 4) | (char2 >> 4);
        unsigned char index3 = ((char2 & 15) << 2) | (char3 >> 6);
        unsigned char index4 = char3 & 63;

        encoded += base64_chars[index1];
        encoded += base64_chars[index2];
        encoded += (i + 1 < input_length) ? base64_chars[index3] : '=';
        encoded += (i + 2 < input_length) ? base64_chars[index4] : '=';
    }

    return encoded;
}

std::string base64_decode(const std::string& input) {
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string decoded;
    size_t input_length = input.length();

    // Base64 디코딩 테이블을 생성합니다.
    unsigned char decoding_table[256];
    for (size_t i = 0; i < 64; ++i) {
        decoding_table[base64_chars[i]] = static_cast<unsigned char>(i);
    }

    size_t i = 0;
    while (i < input_length) {
        unsigned char char1 = input[i++];
        unsigned char char2 = input[i++];
        unsigned char char3 = input[i++];
        unsigned char char4 = input[i++];

        unsigned char index1 = decoding_table[char1];
        unsigned char index2 = decoding_table[char2];
        unsigned char index3 = decoding_table[char3];
        unsigned char index4 = decoding_table[char4];

        unsigned char byte1 = (index1 << 2) | (index2 >> 4);
        unsigned char byte2 = (index2 << 4) | (index3 >> 2);
        unsigned char byte3 = (index3 << 6) | index4;

        decoded += byte1;
        if (char3 != '=')
            decoded += byte2;
        if (char4 != '=')
            decoded += byte3;
    }

    return decoded;
}

int main() {
    std::string input = "Navis";  // 인코딩할 문자열

    std::string encoded = base64_encode(input);  // Base64로 인코딩합니다

    std::cout << encoded << std::endl;  // 인코딩된 문자열을 출력합니다

    //

    std::string input2 = "TmF2a2luZ2RvbQ==";

    std::string decoded = base64_decode(input2);  // Base64로 인코딩합니다

    std::cout << decoded << std::endl;  // 인코딩된 문자열을 출력합니다

    return 0;
}
