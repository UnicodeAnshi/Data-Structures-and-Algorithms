#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums) {
    int ts = accumulate(nums.begin(), nums.end(), 0);
    if (ts % 2 != 0) {
        return false;
    }
    
    int target = ts / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int itr : nums) {
        for (int j = target; j >= itr; j--) {
            dp[j] = dp[j] || dp[j - itr];
        }
    }
    
    return dp[target];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (solve(nums)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}