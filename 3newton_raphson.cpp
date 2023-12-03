#include<bits/stdc++.h>

using namespace std;

const double dif = 1e-2;

class newtonRaphson{
    public:
    double f(double x){
        return x*x*x + x*x - 2;
    }

    double ddxf(double x){
        return 3*x*x+2*x;
    }

    double NewtonRaphson(double x){
        double h = f(x)/ddxf(x);
        while (abs(h) > dif) {
            // h = f(x)/ddxf(x);
            x = x - h;
            h = f(x)/ddxf(x);
        }
        return x;
    }
};

int main()
{
    cout << fixed << setprecision(6);
    srand(time(0));
    newtonRaphson raphson;
    for (int i = 0; i < 10; i++) {
        double root = rand();
        cout << "assump : " << root << " ";
        root = raphson.NewtonRaphson(root);
        cout << "final root : " << root << endl;
    }
    return 0;
}
