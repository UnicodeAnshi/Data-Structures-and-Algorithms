#include<bits/stdc++.h>
using namespace std;

void permute(string str, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            swap(str[l], str[i]);
        }
    }
}

int main() {
    string input;
    cin >> input;

    sort(input.begin(), input.end());

    vector<string> permutations;
    permute(input, 0, input.size() - 1, permutations);

    sort(permutations.begin(), permutations.end());
    cout<<endl<<"Output:"<<endl;
    for (auto itr : permutations) {
        cout << itr << endl;
    }

    return 0;
}
