#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

class Lagrange{
    public :
    double lagrange(vector<Point>points, double value){
        int n = points.size();
        double res = 0;
        for (int i = 0; i < n; i++) {
            double up = 1, down = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                up *= (value - points[j].x);
                down *= (points[i].x - points[j].x);
            }
            res += (up * points[i].y)/down;
        }
        return res;
    }
};

int main()
{
    Lagrange formula;
    vector<Point>points;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }
    double ans = formula.lagrange(points, value);
    cout << ans << endl;
    return 0;
}
/*
323.5
321.0 2.50651
322.8 2.50893
324.2 2.51081
325.0 2.51188
ans -> 2.50987
*/