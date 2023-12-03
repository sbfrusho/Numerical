#include<bits/stdc++.h>

using namespace std;

class GuassElimination{
    public :
    void swaprow(vector<vector<double>>&mat, int i, int j){
        int N = mat.size();
        for (int k = 0; k <= N; k++) {
            swap(mat[i][k], mat[j][k]);
        }
    }

    int forwardEli(vector<vector<double>>&mat){
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

    vector<double> gauss(vector<vector<double>>&mat){
        int N = mat.size();
        int flag = forwardEli(mat);
        if (flag != -1) {
            if (mat[flag][N]) cout << "inconsistant\n";
            else cout << "many solve\n";
            return {};
        }
        vector<double>x = backsub(mat);
        return x;
    }
};

int main()
{
    GuassElimination formula;
    int N;
    cin >> N;
    vector<vector<double>>mat(N, vector<double>(N+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++)
            cin >> mat[i][j];
    }
    vector<double>x = formula.gauss(mat);
    cout << fixed << setprecision(6);
    for (auto it : x) {
        cout << it << endl;
    }
    return 0;
}
/*
3
3.0 2.0 -4.0 3.0
2.0 3.0 3.0 15.0
5.0 -3 1.0 14.0
ans -> 
3.000000
1.000000
2.000000
*/