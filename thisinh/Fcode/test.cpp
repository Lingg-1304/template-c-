#include <iostream>
#include <string>

int main() {
    std::string input;
    //std::cout << "Nhap mot chuoi: ";
    
    std::getline(std::cin, input);
    
    // Kiểm tra nếu chuỗi chứa ký tự xuống dòng
    if (input.find('\n') != std::string::npos) {
        std::cout << "Chuoi co ky tu xuong dong (\\n)" << std::endl;
    } else {
        std::cout << "Chuoi khong co ky tu xuong dong (\\n)" << std::endl;
    }

    std :: cout << std :: endl << input;
    
    return 0;
}