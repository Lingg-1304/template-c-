#include <iostream>
#include <vector>

// Hàm cập nhật giá trị của một phần tử trong cây Fenwick
void update(std::vector<int>& BIT, int index, int value) {
    int n = BIT.size() - 1;
    for (; index <= n; index += index & -index) {
        BIT[index] += value;
    }
}

// Hàm tính tổng các phần tử từ đầu đến một vị trí index trong cây Fenwick
int query(std::vector<int>& BIT, int index) {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += BIT[index];
    }
    return sum;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> A(n + 1, 0); // Dãy số A, được lưu trong cây Fenwick
    std::vector<int> BIT(n + 1, 0); // Cây Fenwick

    for (int i = 1; i <= n; i++) {
        int val;
        std::cin >> val;
        A[i] = val;
        update(BIT, i, val); // Khởi tạo cây Fenwick ban đầu
    }

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, v;
            std::cin >> l >> r >> v;
            update(BIT, l, v);
            update(BIT, r + 1, -v); // Trừ đi giá trị tại r+1 để duy trì tính chất cộng v vào l đến r
        } else if (op == 2) {
            int u;
            std::cin >> u;
            int result = query(BIT, u);
            std::cout << result << std::endl;
        } else if (op == 3) {
            int l, r;
            std::cin >> l >> r;
            int result = query(BIT, r) - query(BIT, l - 1); // Tính tổng các phần tử từ l đến r
            std::cout << result << std::endl;
        }
    }

    return 0;
}
