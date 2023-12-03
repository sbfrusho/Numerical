#include<bits/stdc++.h>

using namespace std;

class LinearSystem{
    public :
    void swaprow(vector<vector<double>>&mat, int i, int j){
        int N = mat.size();
        for (int k = 0; k <= N; k++) {
            swap(mat[i][k], mat[j][k]);
        }
    }

    int echelon(vector<vector<double>>&mat){
        int N = mat.size();
        for (int k = 0; k < N; k++) {
            double v_max = mat[k][k];
            int i_max = k;
            for (int i = k+1; i < N; i++) {
                if (abs(mat[i][k]) > v_max) {
                    v_max = mat[i][k];
                    i_max = i;
                }
            }
            if (!mat[k][i_max]) return k;
            if (i_max != k)
                swaprow(mat, i_max, k);
            for (int i = k+1; i < N; i++) {
                double f = mat[i][k]/mat[k][k];
                for (int j = k+1; j <= N; j++)
                    mat[i][j] -= mat[k][j]*f;
                mat[i][k] = 0;
            }
        }
        return -1;
    }

    vector<double> backsub(vector<vector<double>>&mat){
        int N = mat.size();
        vector<double>x(N);
        for (int i = N-1; i >= 0; i--) {
            x[i] = mat[i][N];
            for (int j = i+1; j < N; j++)
                x[i] -= mat[i][j]*x[j];
            x[i] /= mat[i][i];
        }
        return x;
    }

    vector<double> solve(vector<vector<double>>&mat){
        int N = mat.size();
        int flag = echelon(mat);
        if (flag != -1) {
            if (mat[flag][N]) cout << "inconsistant\n";
            else cout << "many solve\n";
            return {};
        }
        vector<double>x = backsub(mat);
        return x;
    }
};

struct Point{
    double x, y;
};

class PolynomialCurve{
    public :
    vector<double> polynomialcurve(vector<Point>points, int N){
        int n = points.size();
        vector<vector<double>>mat(N, vector<double>(N+1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N; j++) {
                if (i+j == 0) mat[i][j] = n;
                else if (j < N) {
                    for (int k = 0; k < n; k++) {
                        int tmp = i + j - 1;
                        double r = points[k].x;
                        while (tmp--) r *= points[k].x;
                        mat[i][j] += r;
                    }
                } else {
                    for (int k = 0; k < n; k++) {
                        double r = points[k].y;
                        int tmp = i;
                        while (tmp--) r *= points[k].x;
                        mat[i][j] += r;
                    }
                }
            }
        }
        LinearSystem equation;
        vector<double>a = equation.solve(mat);
        return a;
    }
};

int main()
{
    PolynomialCurve curve;
    vector<Point>points;
    int n;
    cin >> n;
    double x, y;
    while (cin >> x >> y) {
        points.push_back({x, y});
    }
    vector<double>a = curve.polynomialcurve(points, n);
    cout << fixed << setprecision(6);
    for (int i = 0; i < a.size(); i++) {
        cout << "a" << i << " = " << a[i] << endl;
    }
    return 0;
}
/*
3
0 1
1 6
2 17
ans -> 
a0 = 1.000000
a1 = 2.000000
a2 = 3.000000

2
0 -1
2 5
5 12
7 20
ans -> 
a0 = -1.137931
a1 = 2.896552
*/