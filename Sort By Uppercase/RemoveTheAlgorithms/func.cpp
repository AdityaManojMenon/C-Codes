#include <string>
#include <vector>
#include <iterator>

int Func(int a) 
{
    std::vector<int> b(a);
    int value = 12;
    for (std::vector<int>::iterator iter = b.begin(); iter != b.end(); ++iter) {
        *iter = value++;
    }
    std::vector<int> c(b.rbegin(), b.rend());

    for (int i = 0; i < static_cast<int>(b.size()); ++i) {
        b.at(i) = 2 * b.at(i) + c.at(i);
    }

    int result = 0;
    for (std::vector<int>::iterator iter = b.begin() + 2; iter != b.end() - 2; ++iter) {
        if (std::to_string(*iter).find("2") != std::string::npos) {
            ++result;
        }
    }
    return result;
}
