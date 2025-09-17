#include <iomanip>

void assignment2_part2(int x, size_t y, char** names) {
    std::cout << "\n對齊後的學生名單:" << std::endl;
    for (int i = 0; i < x; ++i) {
        std::cout << std::left << std::setw(y) << names[i]
                  << " (長度: " << strlen(names[i]) << ")" << std::endl;
    }

    for (int i = 0; i < x; ++i) delete[] names[i];
    delete[] names;
    std::cout << "\n已釋放動態陣列記憶體。\n";
}
