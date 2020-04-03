/*
 * @Author: Hellcat
 * @Date: 2020-02-01 23:29:16
 */
#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;      // 偏差值 有时用1e-10

int sgn(int x) {     // 判断x是否等于0
	if(fabs(x) < eps) return 0;
	else return x < 0 ? -1 : 1;
}

int dcmp(double x, double y) { // 比较两个浮点数
	if(fabs(x - y) < eps) return 0;
	else return x < y ? - 1 : 1;
}

// 点的表示
struct Point{
	double x, y;
	Point(){}
	Point(double x, double y) : x(x), y(y) {}
};

Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x , a.y + b.y);
}

// 两点之间距离
double Distance(Point A, Point B) { return hypot(A.x - B.x , A.y - B.y); }

// 用点的数据表示向量
typedef Point Vector;

// 向量的点积
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }

// 向量的叉积
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

// 直线 P = P0 + vt
struct Line
{
	Point p1, p2;
	Line() {}
	Line(Point p1, Point p2) : p1(p1), p2(p2) {}
	// 根据点和倾斜角确定直线
	Line(Point p, double angle) {
		p1 = p;
		if(sgn(angle - pi/2) == 0) { p2 = (p1 + Point(0, 1)); }
		else {
			p2 = (p1 + Point(1, tan(angle)));
		}
	}
	// ax + by + c = 0
	Line(double a, double b, double c) {
		if(sgn(a) == 0) {
			p1 = Point(0,-c/b);
			p2 = Point(1,-c/b);
		}
		else if(sgn(b) == 0) {
			p1 = Point(-c/a,0);
			p2 = Point(-c/a,1);
		}
		else {
			p1 = Point(0,-c/b);
			p2 = Point(1,(-c-a)/b);
		}
	}
};
