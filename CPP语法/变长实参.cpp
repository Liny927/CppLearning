/*
 * @Author: Hellcat
 * @Date: 2020-03-29 22:25:57
 */
// variadic templates 数量不定的模板参数 (变长实参)
#include <iostream>
#include <bitset>
using namespace std;

void printx() {}

template <typename T, typename... Types>
void printx(const T& firstArg, const Types&... args) {
    cout<<sizeof...(args)<<endl;
    cout<<firstArg<<endl;
    printx(args...); // 需要考虑无参数的情况
}

int main() {
    printx(7.5, "hello world", string("我再hello world"),
    bitset<16>(377), 42);
}
