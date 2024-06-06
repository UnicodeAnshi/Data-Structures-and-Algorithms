#include<bits/stdtr1c++.h>
using namespace std;

int solve(vector<int> &dp) {
    int n = dp.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    
    for (int chain_length = 2; chain_length <= n; chain_length++) {
        for (int i = 0; i < n - chain_length + 1; i++) {
            int j = i + chain_length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + dp[i] * dp[k + 1] * dp[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> dim;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (i == 0) {
            dim.push_back(a);
        }
        dim.push_back(b);
    }
    int result = solve(dim);
    cout << result << endl;
    
} 
