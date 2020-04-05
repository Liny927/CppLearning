/*
 * @Author: Hellcat
 * @Date: 2020-03-31 13:25:03
 */
#include <iostream>
using namespace std;

class P {
public:
    P(int a, int b): m_a(a), m_b(b), m_c(0) {}
    explicit P(int a, int b, int c): m_a(a), m_b(b), m_c(c) {}
private:
    int m_a, m_b, m_c;
};

int main() {
    P a {77, 5, 32};
    P b(77, 5, 32);
    // P c = {77, 5, 43}; // 若存在explicit 则有
    P c = {77, 2}; // ok
    // Error: 复制列表初始化不能使用标记为“显式”的构造函数
}
