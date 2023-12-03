#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

class NewtonForward{
    public :

    double cal_u(double u, int n){
        double res = u;
        for (int i = 1; i < n; i++)
            res *= (u - i);
        return res;
    }

    long long int fact(int x){
        long long int res = 1;
        for (long long int i = 2; i <= x; i++)
            res *= x;
        return res;
    }

    double newtonforward(vector<Point>points, double value){
        int n = points.size();
        double y[n][n];
        for (int i = 0; i < n; i++)
            y[i][0] = points[i].y;
        // calculating tabular value
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
        double res = y[0][0];
        double u = (value - points[0].x)/(points[1].x - points[0].x);
        for (int i = 1; i < n; i++) {
            res += cal_u(u, i)*y[0][i]/(double)fact(i);
        }
        return res;
    }
};

int main()
{
    NewtonForward formula;
    vector<Point>points;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }
    double ans = formula.newtonforward(points, value);
    cout << ans << endl;
    return 0;
}
/*
0.12
0.10 0.1003
0.15 0.1511
0.20 0.2027
0.25 0.2553
0.30 0.3093
ans -> 0.120529
*/