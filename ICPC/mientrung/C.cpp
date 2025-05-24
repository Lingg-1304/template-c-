#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // std::gcd

using namespace std;

const int MOD = 1e9 + 7;

// Hàm tính LCM của hai số
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // Tránh tràn số
}

void solve_case(int N, const vector<int>& A) {
    // Sử dụng unordered_map để lưu số lần mỗi LCM xuất hiện
    unordered_map<int, int> dp;
    
    // Duyệt qua từng phần tử trong mảng
    for (int num : A) {
        unordered_map<int, int> new_dp = dp;  // Copy dp hiện tại để tính toán mới
        for (auto& [l, count] : dp) {
            int new_lcm = lcm(l, num);  // Tính LCM của tập hiện tại với num
            if (new_lcm <= 500) {  // Chỉ xét các giá trị LCM <= 500 (vì A[i] <= 500)
                new_dp[new_lcm] = (new_dp[new_lcm] + count) % MOD;
            }
        }
        new_dp[num] = (new_dp[num] + 1) % MOD;  // Thêm tập con chỉ chứa num
        
        // Cập nhật lại dp
        dp = new_dp;
    }
    
    // Tính tổng tất cả các giá trị LCM
    long long total_sum = 0;
    for (auto& [l, count] : dp) {
        total_sum = (total_sum + (long long)l * count) % MOD;
    }
    
    cout << total_sum << endl;
}

int main() {
    int T;
    cin >> T;  // Số lượng test case
    while (T--) {
        int N;
        cin >> N;  // Số phần tử trong dãy
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];  // Dãy số A
        }
        solve_case(N, A);
    }
    return 0;
}
