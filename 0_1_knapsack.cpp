#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(int W, vector<Item>& items, vector<int>& selectedItems) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (items[i-1].weight <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - items[i-1].weight] + items[i-1].value);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int w = W;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            selectedItems.push_back(i-1);
            w -= items[i-1].weight;
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int W;
    cin >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = {weights[i], values[i]};
    }

    vector<int> selectedItems;
    int maxValue = knapsack(W, items, selectedItems);

    cout << "Value = " << maxValue << endl;
    cout << "Weights selected : ";
    for (int i : selectedItems) {
        cout << items[i].weight << " ";
    }
    cout << endl;
    cout << "Values of selected weights : ";
    for (int i : selectedItems) {
        cout << items[i].value << " ";
    }
    cout << endl;

    return 0;
}
