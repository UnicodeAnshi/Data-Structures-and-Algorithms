#include<bits/stdc++.h>
using namespace std;

int countWaysToMakeSum(vector<int> &coins, int targetSum) {
    vector<int> dp(targetSum + 1, 0);
    dp[0] = 1;

    for (int itr : coins) {
        for (int sumValue = itr; sumValue <= targetSum; ++sumValue) {
            dp[sumValue] += dp[sumValue - itr];
        }
    }

    return dp[targetSum];
}

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int targetSum;
    cin >> targetSum;

    int ans = countWaysToMakeSum(coins, targetSum);
    cout <<ans << endl;

    return 0;
}
