#include <iostream>
#include <vector>

// Hàm tạo dãy Fibonacci nhỏ hơn hoặc bằng số n
std::vector<int> generateFibonacci(int max) {
    std::vector<int> fib = {1, 2}; // Các số Fibonacci đầu tiên
    while (true) {
        int next = fib.back() + fib[fib.size() - 2];
        if (next > max) break;
        fib.push_back(next);
    }
    return fib;
}

// Hàm đệ quy tìm các cách phân tích thành tích của các số Fibonacci
void findFactors(int n, int start, const std::vector<int>& fib, std::vector<int>& current, std::vector<std::vector<int>>& results) {
    if (n == 1) {  // Nếu tích hiện tại bằng n, ta lưu kết quả
        results.push_back(current);
        return;
    }

    for (int i = start; i < fib.size() && fib[i] <= n; i++) {
        if (n % fib[i] == 0) { // Nếu fib[i] là ước của n
            current.push_back(fib[i]);
            findFactors(n / fib[i], i, fib, current, results); // Tìm tiếp cho n/fib[i]
            current.pop_back();
        }
    }
}

int main() {
    int n = 64;

    // Tạo dãy Fibonacci nhỏ hơn hoặc bằng n
    std::vector<int> fib = generateFibonacci(n);

    // Kết quả lưu các cách phân tích
    std::vector<std::vector<int>> results;
    std::vector<int> current;

    // Tìm tất cả các cách phân tích
    findFactors(n, 0, fib, current, results);

    // In kết quả
    std::cout << "Các cách viết " << n << " dưới dạng tích của các số Fibonacci:\n";
    for (const auto& res : results) {
        for (int num : res) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
