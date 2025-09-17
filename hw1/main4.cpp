#include <string>
#include <vector>

void assignment2_part1(int& x, size_t& y, char**& names) {
    std::cout << "請輸入學生人數x: ";
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> temp_names;
    y = 0;

    std::cout << "請依序輸入 " << x << " 位學生的英文全名:" << std::endl;
    for (int i = 0; i < x; ++i) {
        std::string name;
        std::cout << "學生 " << i + 1 << ": ";
        std::getline(std::cin, name);
        temp_names.push_back(name);
        if (name.length() > y) y = name.length();
    }

    names = new char*[x];
    for (int i = 0; i < x; ++i) {
        names[i] = new char[y + 1];
        strcpy(names[i], temp_names[i].c_str());
    }
}
