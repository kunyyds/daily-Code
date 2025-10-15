#include <iostream>
#include <string>

void sink(std::string s)
{
    std::cout << "Sink: " << s << "\n";
}

template <typename T>
void wrapper_copy(const T &arg)
{
    std::cout << "Inside wrapper_copy\n";
    sink(arg); // 触发拷贝
}

int main()
{
    std::string s = "Alice";

    // Case 1: 左值
    wrapper_copy(s); // T = std::string, arg = const std::string& → 拷贝

    // Case 2: std::move(s)
    wrapper_copy(std::move(s)); // T = std::string, arg = const std::string& → 仍然拷贝！

    // Case 3: 字符串字面量
    wrapper_copy("Bob"); // T = const char*, arg = const char*& → 合法

    return 0;
}