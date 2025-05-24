#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm giải quyết vấn đề
int solve(int N, int W, int H, vector<pair<int, int>>& items) {
    int max_value = 0; // Giá trị tối đa ban đầu
    vector<pair<int, int>> within_W; // Các vật phẩm nằm trong trọng lượng balo W
    vector<pair<int, int>> within_H; // Các vật phẩm có thể cầm tay (trọng lượng <= H)

    // Phân loại vật phẩm vào 2 nhóm: có thể bỏ vào balo (<= W) và có thể cầm tay (<= H)
    for (int i = 0; i < N; i++) {
        if (items[i].first <= W) {
            within_W.push_back(items[i]); // Vật phẩm có thể bỏ vào balo
        }
        if (items[i].first <= H) {
            within_H.push_back(items[i]); // Vật phẩm có thể cầm tay
        }
    }

    // Tìm giá trị tối đa trong trường hợp không thêm vật phẩm cầm tay
    for (int i = 0; i < within_W.size(); i++) {
        max_value = max(max_value, within_W[i].second);
    }

    // Thử thêm 1 vật phẩm cầm tay
    for (int i = 0; i < within_W.size(); i++) {
        for (int j = 0; j < within_H.size(); j++) {
            // Kiểm tra nếu ta có thể mang thêm vật phẩm cầm tay mà không làm vượt quá trọng lượng W
            if (within_W[i].first + within_H[j].first <= W) {
                max_value = max(max_value, within_W[i].second + within_H[j].second);
            }
        }
    }

    return max_value;
}

int main() {
    // Đọc đầu vào
    int N, W, H;
    cin >> N >> W >> H;
    
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second; // Nhập trọng lượng và giá trị của vật phẩm
    }
    
    // Tính toán và in ra kết quả
    cout << solve(N, W, H, items) << endl;
    
    return 0;
}
