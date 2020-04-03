/*
 * @Author: Hellcat
 * @Date: 2020-03-28 19:27:52
 */
#include <bits/stdc++.h>
using namespace std;

class Fraction {
public:
    // non-explicit-one-argument ctor
    // explicit 显式构造
    explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    operator double() const { // 转换函数
        return (double) m_numerator / m_denominator;
    }
    Fraction operator + (const Fraction& f) {
        return Fraction(m_numerator + f.m_numerator, m_denominator + f.m_denominator);
    }
public:
    int m_numerator;   // 分子
    int m_denominator; // 分母
};

int main() {
    Fraction f(3,5);
    double d = 4 + f;
    // Fraction d2 = 4 + f; // [Error] (无explicit)ambiguous
    cout<<d<<endl; // 4.6
    // double c = b;
    // cout<<c<<endl;
}
