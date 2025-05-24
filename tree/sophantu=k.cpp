#include <iostream>
#include <vector>

// Hàm cập nhật giá trị tại vị trí index trong cây Fenwick
void update(std::vector<int>& fenwick, int index, int value) {
    while (index < fenwick.size()) {
        fenwick[index] += value;
        index += index & -index; // Cập nhật tất cả các nút cha của nút hiện tại
    }
}

// Hàm lấy tổng tiền tố từ đầu đến vị trí index trong cây Fenwick
int query(std::vector<int>& fenwick, int index) {
    int sum = 0;
    while (index > 0) {
        sum += fenwick[index];
        index -= index & -index; // Lấy tổng của các nút con của nút hiện tại
    }
    return sum;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N + 1, 0); // Mảng A (index từ 1 đến N)
    std::vector<int> fenwick(N + 1, 0); // Cây Fenwick (index từ 1 đến N)

    for (int i = 1; i <= N; i++) {
        int num;
        std::cin >> num;
        A[i] = num;
        update(fenwick, i, 1); // Cập nhật cây Fenwick với tần suất của phần tử num
    }

    for (int i = 0; i < Q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;

        int count = query(fenwick, r) - query(fenwick, l - 1); // Đếm số phần tử k trong đoạn [l..r]
        std::cout << "Số lượng phần tử " << k << " trong đoạn [" << l << ".." << r << "] là: " << count << std::endl;
    }

    return 0;
}
