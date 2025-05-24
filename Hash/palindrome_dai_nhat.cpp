#include <iostream>
#include <string>
#include <vector>

// Hàm tính giá trị băm của một xâu s
unsigned long long calculateHash(const std::string& s) {
    const int prime = 31; // Số nguyên tố để tránh xung đột
    unsigned long long hashValue = 0;
    unsigned long long primePower = 1;

    for (char c : s) {
        hashValue += (c - 'a' + 1) * primePower;
        primePower *= prime;
    }

    return hashValue;
}

// Hàm kiểm tra xâu con có đối xứng không
bool isPalindrome(const std::string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int longestPalindromeSubstring(const std::string& s) {
    int maxLength = 0;
    int start = 0;
    int n = s.length();

    std::vector<unsigned long long> prefixHash(n, 0);
    prefixHash[0] = s[0] - 'a' + 1;

    // Tính giá trị băm tiền tố cho từng ký tự trong xâu
    for (int i = 1; i < n; i++) {
        prefixHash[i] = prefixHash[i - 1] * 31 + (s[i] - 'a' + 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            unsigned long long subHash;
            if (i == 0) {
                subHash = prefixHash[j];
            } else {
                subHash = prefixHash[j] - prefixHash[i - 1];
            }

            if (isPalindrome(s, i, j) && subHash == calculateHash(s.substr(i, j - i + 1))) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    start = i;
                }
            }
        }
    }

    //std::cout << "Xâu con đối xứng dài nhất: " << s.substr(start, maxLength) << std::endl;
    return maxLength;
}

int main() {
	int n; std::cin >> n;
    std::string input;
    //std::cout << "Nhập xâu ký tự: ";
    std::cin >> input;

    int result = longestPalindromeSubstring(input);
    std::cout << result << std::endl;

    return 0;
}
