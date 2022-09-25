/**
** Questão E - Abobora 2022
** Cova de Aboboras - Athos
**
** Sei la que porra era pra fazer
**/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

void processo(vvi &dp, vvi &c, int n, int m){
    for(int i = 1; i <= n; i++)
        dp[i][1] = c[i-1][0]+dp[i-1][1];
    for(int j = 1; j <= m; j++)
        dp[1][j] = c[0][j-1]+dp[1][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+c[i-1][j-1];
        }
    }
    return;
}

int solv(vvi &dp, int a, int b, int c, int d){
    return dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
}

void leitura(vvi &c, int n, int m){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    return;
}

void imprime(vvi &c, int n, int m){
    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main(){
    int n, m, q;
    int a, b, c, d;
    cin >> n >> m >> q;
    vvi dp(n+1, vector<int>(m+1, 0)), cova(n, vector<int>(m, 0));
    leitura(cova, n, m);
    processo(dp, cova, n, m);
    while(q--){
        cin >> a >> b >> c >> d;
        cout << solv(dp, a, b, c, d) << endl;
    }
    return 0;
}