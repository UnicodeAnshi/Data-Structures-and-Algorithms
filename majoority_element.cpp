#include <bits/stdc++.h>
using namespace std;
bool findMajorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = -1;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    // Verifying if the candidate is actually the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    return (count > nums.size() / 2) ? true : false;
}

// Function to find the median of the array
double findMedian(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    } else {
        return nums[n / 2];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (findMajorityElement(nums)) {
        cout << "yes"<<endl;
    } else {
        cout << "No " << endl;
    }
    
    // Find and print median
    double median = findMedian(nums);
    cout << median << endl;

    return 0;
}
