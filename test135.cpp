/*
 * @Author: Hellcat
 * @Date: 2020-04-01 11:22:43
 */
#include <iostream>
#include <cmath>
#include <memory>
#include <cassert>
using namespace std;

class Point {
public:
    Point(): m_x(0), m_y(0) {
        cout<<"Default ctor called."<<endl;
    }
    Point(int x, int y) : m_x(x), m_y(y) {
        cout<<"Args ctor called."<<endl;
    }
    ~Point() { cout<<"Dtor called."<<endl; }
    int getX() const { return m_x; cout<<"fewf"<<endl; }
    int getY() const { return m_y; }
    void move(const int& newX, const int& newY) {
        m_x = newX;
        m_y = newY;
    }
private:
    int m_x, m_y;
};

class ArrayOfPoints {
public:
    ArrayOfPoints(int size): m_size(size) {
        points = new Point[size];
    }
    ~ArrayOfPoints() {
        cout<<"Deleting..."<<endl;
        delete[] points;
    }
    Point& element(const int idx) {
        assert(idx >= 0 && idx < m_size);
        return points[idx];
    }
private:
    Point* points;
    int m_size;
};


int main() {
    int cnt;
    cout<<"Please enter the count of points: ";
    cin>>cnt;
    ArrayOfPoints points(cnt);
    points.element(0).move(5, 0);
    points.element(1).move(15, 20);
}
