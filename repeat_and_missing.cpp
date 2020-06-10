/*
From the set of n positive integer one number is repeated twice and one is missing
Find those numbers.
1 <= v[i] <= n

Solution 1 -> For repeated number, use negative indexing method, find missing number from repeated number
Solution 2 -> use two equation, sum of elements and sum of square of elements
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n; 
    ll sum = 0;
    vector < int > v(n);
    for(auto &x: v) {
        cin >> x;
        sum += x;
    }
    
    int repeated = 1;
    for(int i = 0; i < n; i ++) {
        int x = abs(v[i]);
        if(v[x - 1] < 0) {
            repeated = x;
            break;
        }
        v[x - 1] = -v[x - 1];
    }
    ll x = sum - (n * 1LL * (n + 1)) / 2;
    ll missing = repeated - x;
    cout << repeated << " " << missing << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}