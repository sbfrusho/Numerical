#include<bits/stdc++.h>

using namespace std;

const int lb = -1000;
const int ub = 1000;
const double diff = 0.0000001;

class Bisection{
    public :
    double func(double x){
        return x*x*x - x*x + 2;
    }

    void bisection(double a, double b){
        if (func(a) * func(b) >= 0) {
            cout << "You have not assumed right a and b\n";
            return;
        }
        double root = a;
        while ((b-a) >= diff) {
            root = (a+b)/2;
            cout << "range : " << a << " " << b << " : ";
            cout << " let the root be " << root << endl;
            if (func(root) == 0.0)
                break;
            else if (func(root)*func(a) > 0)
                a = root;
            else
                b = root;
        }
        cout << "The value of root is : " << root;
    }
};

int main()
{
    cout << fixed << setprecision(10);
    srand(time(0));
    Bisection bisec;
    double a, b;
    //for (int i = 0; i < 5; i++) {
    // cin >> a >> b;
    do {
        a = (rand() % (ub - lb + 1)) + lb;
    } while (bisec.func(a) > 0);
    do {
        b = (rand() % (ub - lb + 1)) + lb;
    } while (bisec.func(b) < 0);
    cout << "in range [" << a << ", " << b << "] : ";
    bisec.bisection(a, b);
    //cout << endl;
    //}
    return 0;
}
