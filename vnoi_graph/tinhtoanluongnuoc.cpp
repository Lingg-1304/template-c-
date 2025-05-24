#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> heights(M, vector<int>(N));

    // Đọc chiều cao của các cột
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> heights[i][j];
        }
    }

    int total_water = 0;

    // Duyệt qua từng ô (i,j) và tính lượng nước đọng lại
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int current_height = heights[i][j];
            int max_height_around = current_height;

            if (i > 0) {
                max_height_around = max(max_height_around, heights[i - 1][j]);
            }
            if (i < M - 1) {
                max_height_around = max(max_height_around, heights[i + 1][j]);
            }
            if (j > 0) {
                max_height_around = max(max_height_around, heights[i][j - 1]);
            }
            if (j < N - 1) {
                max_height_around = max(max_height_around, heights[i][j + 1]);
            }

            if (current_height < max_height_around) {
                total_water += max_height_around - current_height;
            }
        }
    }

    // Xuất kết quả
    cout << total_water << endl;

    return 0;
}