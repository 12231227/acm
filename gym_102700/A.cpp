#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

const double pi = acos(-1.0);
const double inf = 1e100;
const double eps = 1e-6; //精度
//floor(x)向下取整 ceil(x)向上取整 round(x)四舍五入

int sgn(double d)
{
    if (fabs(d) < eps)
        return 0;
    if (d > 0)
        return 1;
    return -1;
}

struct Point
{ //点
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector; //向量

Vector operator+(Vector A, Vector B)
{
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator-(Point A, Point B)
{
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator*(Vector A, double p)
{
    return Vector(A.x * p, A.y * p);
}

Vector operator/(Vector A, double p)
{
    return Vector(A.x / p, A.y / p);
}

bool operator<(const Point &a, const Point &b)
{ //left and low 先左至右，相同的上到下
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool operator==(const Point &a, const Point &b)
{ //计算精度内相等
    if (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0)
        return true;
    return false;
}

double Dot(Vector A, Vector B)
{ //点乘
    return A.x * B.x + A.y * B.y;
}

double Length(Vector A)
{ //模
    return sqrt(Dot(A, A));
}

double Angle(Vector A, Vector B)
{ //向量夹角，弧度值
    return acos(Dot(A, B) / Length(A) / Length(B));
}

double Cross(Vector A, Vector B)
{ //叉乘
    return A.x * B.y - A.y * B.x;
}

double Area2(Point A, Point B, Point C)
{ //以A为顶角的平行四边形的有向面积
    return Cross(B - A, C - A);
}

Vector Rotate(Vector A, double rad)
{ //rad为弧度 且为逆时针旋转的角
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(Vector A)
{ //向量A左转90°的单位法向量
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}

bool ToLeftTest(Point a, Point b, Point c)
{ //判断 bc 是否在 ab的逆时针侧
    return Cross(b - a, c - b) > 0;
}

struct Line
{ //直线定义(两点式实现)
    Point v, p;
    Line(Point v, Point p) : v(v), p(p) {} //两点确定一条直线
    Point point(double t)
    { //返回点P = v + (p - v)*t(t为线段长度)
        return v + (p - v) * t;
    }
};

bool PointOnLine(Point p, Line le)
{ //判断点在线上
    Vector alpha = le.v - p;
    Vector beta = le.p - p;
    return (sgn(Cross(alpha, beta)) == 0);
}

int LineProperIntersection(Line a, Line b)
{ //两直线相交，2为重合，1为平行，0为相交
    if (sgn(Cross(a.p - a.v, b.p - b.v)) == 0)
    {
        if (PointOnLine(a.p, b))
        {
            return 2;
        }
        return 1;
    }
    return 0;
}

//调用前保证Cross（v,w）!= 0
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{ //两条点向式直线，调用前需保证直线相交
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

Point GetLineIntersection(Line i, Line j)
{
    return GetLineIntersection(i.p, i.p - i.v, j.p, j.p - j.v);
}

double DistanceToLine(Point P, Point A, Point B)
{ //有向面积法（不加绝对值得到有向距离
    Vector v1 = B - A;
    Vector v2 = P - A;
    return fabs(Cross(v1, v2) / Length(v1));
}

double DistanceToLine(Point P, Line l)
{
    return DistanceToLine(P, l.v, l.p);
}

double DistanceToSegment(Point P, Point A, Point B)
{               //P到线段AB的距离公式
    if (A == B) //点
        return Length(P - A);
    Vector v1 = B - A;
    Vector v2 = P - A;
    Vector v3 = P - B;
    if (sgn(Dot(v1, v2)) < 0)
        return Length(v2);
    if (sgn(Dot(v1, v3)) > 0)
        return Length(v3);
    return DistanceToLine(P, A, B);
}

Point GetLineProjection(Point P, Point A, Point B)
{ //求点在直线上的投影点
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
}

Point GetLineProjection(Point P, Line l)
{
    return GetLineProjection(P, l.p, l.v);
}

bool OnSegment(Point p, Point a1, Point a2)
{ //点是否在线段上(不含端点
    return (PointOnLine(p, Line(a1, a2)) && Dot(a1 - p, a2 - p) < 0);
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{ //两次跨立判断相交
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
    double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    //以下判断允许端点处相交
    if (!sgn(c1) || !sgn(c2) || !sgn(c3) || !sgn(c4))
    {
        bool f1 = OnSegment(b1, a1, a2);
        bool f2 = OnSegment(b2, a1, a2);
        bool f3 = OnSegment(a1, b1, b2);
        bool f4 = OnSegment(a2, b1, b2);
        bool f = (f1 | f2 | f3 | f4);
        return f;
    }

    return (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0);
}

double PolygonArea(Point p[], int n)
{ //多边形面积，p下标从0开始
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (Cross(p[i], p[(i + 1) % n]));
    }
    return fabs(sum) / 2;
}

int isPointInPolygon(Point p, Point poly[], int n)
{ //判断点是否在多边形内，若点在多边形内返回1，在多边形外部返回0，在多边形边上返回-1，在多边形顶点处返回-2
    int wn = 0;
    for (int i = 0; i < n; i++)
    {
        if (poly[i] == p)
            return -2;
    }
    for (int i = 0; i < n; i++)
    {
        if (OnSegment(p, poly[i], poly[(i + 1) % n]))
            return -1;
        int k = sgn(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
        int d1 = sgn(poly[i].y - p.y);
        int d2 = sgn(poly[(i + 1) % n].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0)
            wn++;
        if (k < 0 && d2 <= 0 && d1 > 0)
            wn--;
    }
    if (wn != 0)
        return 1;
    return 0;
}

//皮克定理 对于一个顶点均在格点上的多边形，有 2S = 2a + b - 2
//其中S为多边形面积，a为多边形内部格点数，b为多边形边界上的格点数
//常可求多边形内部格点数
//线段间的格点个数 n = gcd(fabs(y2-y1),fabs(x2-x1)) - 1;
//遍历边后+顶点数即为b

struct Circle
{
    Point c;
    double r;
    Circle(Point c, double r) : c(c), r(r) {}
    Point point(double a)
    { //通过弧度值来求圆上一点的坐标
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

double CircleIntersectionArea(Circle a, Circle b)
{
    double d, s, t, a1, a2, s1, s2, s3;
    double x1 = a.c.x, y1 = a.c.y, r1 = a.r, x2 = b.c.x, y2 = b.c.y, r2 = b.r;
    if (r1 < r2)
        swap(r1, r2);
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (sgn(d - (r1 + r2)) >= 0)
        return 0;
    else if (sgn(d - (r1 - r2)) <= 0)
        s = pi * r2 * r2;
    else
    {
        a1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        a2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        s1 = a1 * r1 * r1;
        s2 = a2 * r2 * r2;
        s3 = r1 * sin(a1) * d;
        s = s1 + s2 - s3;
    }
    return s;
}

double compare(Point a, Point b, Point c)
{ //计算极角
    return Cross(b - a, c - a);
}

bool cmp2(Point a, Point b)
{
    Point c; //原点，一般全局变量即可
    c.x = 0;
    c.y = 0;
    if (sgn(compare(c, a, b)) == 0) //计算叉积，函数在上面有介绍，如果叉积相等，按照X从小到大排序
        return a.x < b.x;
    else
        return compare(c, a, b) > 0;
}

Point C;

bool cmp3(Point a, Point b)
{
    Point vA = a - C;
    Point vB = b - C;
    bool aCote = vA.y > 0, bCote = vB.y > 0;
    if (aCote && bCote)
        return -vA.x * abs(vB.y) < -vB.x * abs(vA.y);
    else if (aCote)
        return 1;
    else if (bCote)
        return 0;
    else
        return -vA.x * abs(vB.y) > -vB.x * abs(vA.y);
}

inline double mul2(double x)
{
    return x * x;
}

pair<pair<double, double>, pair<double, double>> CircleIntersectionPoint(double x1, double y1, double r1, double x2, double y2, double r2)
{ //计算交点，输入确保有解
    double L = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AE = (mul2(r1) - mul2(r2) + mul2(L)) / (2 * L);
    double x0 = x1 + AE / L * (x2 - x1);
    double y0 = y1 + AE / L * (y2 - y1);
    double CE = sqrt(mul2(r1) - mul2(AE));
    double xc, xd, yc, yd;
    if (y1 - y2 == 0)
    {
        xc = x0;
        yc = y0 + CE;
        xd = x0;
        yd = y0 - CE;
    }
    else
    {
        double K2 = -1 * (x2 - x1) / (y2 - y1);
        xc = x0 - (CE / sqrt(1 + mul2(K2)));
        yc = y0 + K2 * (xc - x0);
        xd = x0 + (CE / sqrt(1 + mul2(K2)));
        yd = y0 + K2 * (xd - x0);
    }
    return make_pair(make_pair(xc, yc), make_pair(xd, yd));
}

int GetTwinCirTangent(Circle A, Circle B, Line Tangent[])
{ //返回-1表示无数条切线（两圆重合）
    int cnt = 0;
    if (A.r < B.r)
        swap(A, B);
    double d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
    double rdiff = A.r - B.r;
    double rsum = A.r + B.r;
    if (sgn(d2 - rdiff * rdiff) < 0) //内含
        return 0;
    if (sgn(d2) == 0 && sgn(A.r - B.r) == 0) //重合
        return -1;

    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);

    if (sgn(d2 - rdiff * rdiff) == 0)
    {                                                        //两圆内切
        Tangent[cnt++] = Line(A.point(base), B.point(base)); //1条外公切线
        return cnt;
    }

    double ang = acos((A.r - B.r) / sqrt(d2));
    Tangent[cnt++] = Line(A.point(base + ang), B.point(base + ang)); //2条外公切线
    Tangent[cnt++] = Line(A.point(base - ang), B.point(base - ang));

    if (sgn(d2 - rsum * rsum) == 0)                               //外切
        Tangent[cnt++] = Line(A.point(base), B.point(pi + base)); //1条内公切线
    else if (sgn(d2 - rsum * rsum) > 0)
    { //相离
        ang = acos((A.r + B.r) / sqrt(d2));
        Tangent[cnt++] = Line(A.point(base + ang), B.point(pi + base + ang)); //2条内公切线
        Tangent[cnt++] = Line(A.point(base - ang), B.point(pi + base - ang));
    }
    //相交
    return cnt;
}

int main(){
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    if (Length(B - A) > Length(C - D)){
        swap(A, C);
        swap(B, D);
    }
    Line l1 = Line(A, B);
    Line l2 = Line(C, D);
    double lens = Length(B - A);
    Point kp = l2.point(lens);
    double ans = DistanceToSegment(B, kp, D);

    double ll = 0;
    double rr = lens;

    while(rr - ll > 1e-14){
        double mid = (rr + ll) / 2;
        double midrr = (mid + rr) / 2;
        double midlens = Length(l1.point(mid) - l2.point(mid));
        double midrrlens = Length(l1.point(midrr) - l2.point(midrr));
        if (midlens < midrrlens)
            rr = midrr;
        else
            ll = mid;
    }

    ans = min(ans, Length(l1.point(ll) - l2.point(ll)));
    printf("%.12lf\n", ans);
    return 0;
} 
