#include<bits/stdc++.h>

using namespace std;

class GuassJordan{
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

    void normal(vector<vector<double>>&mat){
        int N = mat.size();
        for (int k = 0; k < N; k++) {
            double f = mat[k][k];
            for (int i = k; i <= N; i++)
                mat[k][i] /= f;
        }
        for (int k = 0; k < N; k++) {
            for (int i = k-1; i >= 0; i--) {
                double f = mat[i][k];
                for (int j = k; j <= N; j++) {
                    mat[i][j] -= mat[k][k]*f;
                }
            }
        }
    }

    bool gauss(vector<vector<double>>&mat){
        int N = mat.size();
        int flag = echelon(mat);
        if (flag != -1) {
            if (mat[flag][N]) cout << "inconsistant\n";
            else cout << "many solve\n";
            return false;
        }
        normal(mat);
        return true;
    }
};

int main()
{
    GuassJordan formula;
    int N;
    cin >> N;
    vector<vector<double>>mat(N, vector<double>(N+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++)
            cin >> mat[i][j];
    }
    bool exist = formula.gauss(mat);
    cout << fixed << setprecision(6);
    if (exist)
        for (int i = 0; i < N; i++)
            cout << mat[i][N] << endl;
    return 0;
}
/*
3
1 0 0 2.2 
0 2 0 2.8 
0 0 -2.5 -3
ans -> 
2.200000
1.400000
1.200000
*/