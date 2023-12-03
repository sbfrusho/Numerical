#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

class LeastSquareCurve{
    public :
    Point leastsquarecurve(vector<Point>points){
        Point res;
        double n = points.size();
        double x = 0, y = 0, xy = 0, xsq = 0;
        for (auto it : points) {
            x += it.x;
            y += it.y;
            xy += it.x*it.y;
            xsq += it.x*it.x;
        }
        res.y = ((n*xy) - (x*y))/((n*xsq) - (x*x));
        res.x = (y/n) - (res.y*(x/n));
        return res; 
    }
};

int main()
{
    LeastSquareCurve curve;
    vector<Point>points;
    double x, y;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }
    Point p = curve.leastsquarecurve(points);
    cout << "Y = " << p.x << (p.y > 0 ?" + " : " - ") << abs(p.y) << "X\n";
    return 0;
}