#include <iostream>
#include <vector>
#include <array>
#include <iterator>    // std::begin, std::end
#include <string>
#include <string_view>

// 1) Genel "range/container" yazdırma (int[], vector, array, vs.)
template <typename Container>
void print(const Container& c) {
    for (auto it = std::begin(c); it != std::end(c); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

// 2) C-string / std::string / literal için özel sürüm
void print(std::string_view s) {
    std::cout << s << "\n";
}

int main() {
    // --- A) C-array (int[5]) ---
    int myArray[5] = {1, 2, 3, 4, 5};
    std::cout << "C-array: ";
    print(myArray); // template print(Container)

    // --- B) std::vector<int> ---
    std::vector<int> myVector = {10, -2, 30};
    std::cout << "vector:  ";
    print(myVector); // template

    // --- C) std::array<int, 4> ---
    std::array<int, 4> myStdArray = {7, 8, 9, 10};
    std::cout << "std::array: ";
    print(myStdArray); // template

    // --- D) std::string ---
    std::string s = "Bonjour";
    std::cout << "std::string: ";
    print(s); // print(string_view) seçilir

    // --- E) string literal ---
    std::cout << "literal: ";
    print("Salut!"); // print(string_view) seçilir

    // --- F) const char* (C-string) ---
    const char* cstr = "C-string";
    std::cout << "const char*: ";
    print(cstr); // print(string_view) seçilir

    return 0;
}
