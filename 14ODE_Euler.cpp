#include<bits/stdc++.h>

using namespace std;

class ODE_Euler{
    public:
    double fun(double x, double y){
        // y' = x^2 + y
        // y' = dy/dx
        return x*x + y;
    }
    double euler(double x0, double y, double h, double x){
        while (x0 < x) {
            y += h * fun(x0, y);
            x0 += h;
        }
        return y;
    }
};

int main()
{
    ODE_Euler method;
    double x0, y0, h;
    cin >> x0 >> y0 >> h;
    double x; 
    cin >> x;
    double ans = method.euler(x0, y0, h, x);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
/*
y' = x^2 + y
0 1 0.05 0.1 

ans -> 1.102625
*/