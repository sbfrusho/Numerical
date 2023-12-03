#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

class Trapezoidal{
    public:
    double trapezoidal(vector<Point>points, double h){
        double res = points[0].y + points.back().y;
        for (int i = 1; i+1 < points.size(); i++) {
            res += points[i].y*2;
        }
        res *= (h/2);
        return res;
    }
};

int main()
{
    Trapezoidal rule;
    vector<Point>points;
    double x, y, h;
    cin >> h;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }
    double ans = rule.trapezoidal(points, h);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

/*
0.5
0 1
0.5 0.6667
1 0.5
ans -> 0.708350
*/