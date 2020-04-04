/*
 * @Author: Hellcat
 * @Date: 2020-03-29 22:25:57
 */
// variadic templates ����������ģ����� (�䳤ʵ��)
#include <iostream>
#include <bitset>
using namespace std;

void printx() {}

template <typename T, typename... Types>
void printx(const T& firstArg, const Types&... args) {
    cout<<sizeof...(args)<<endl;
    cout<<firstArg<<endl;
    printx(args...); // ��Ҫ�����޲��������
}

int main() {
    printx(7.5, "hello world", string("����hello world"),
    bitset<16>(377), 42);
}
