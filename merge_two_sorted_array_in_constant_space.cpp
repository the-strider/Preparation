#include <bits/stdc++.h>
using namespace std;

int nextgap(int gap) {
    if(gap <= 1) return 0;
    return (gap + 1) / 2;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector < int > v1(n), v2(m);
    for(auto &x: v1) {
        cin >> x;
    }
    for(auto &x: v2) {
        cin >> x;
    }
    
    // swap largest of first vector with smallest of second vector
    for(int i = 0; i < min(n, m); i ++) {
        if(v1[n - i - 1] > v2[i]) {
            swap(v1[n - i - 1], v2[i]);
        }
    }
    
    // sort first vector with shell sort
    for(int gap = nextgap(n); gap > 0; gap = nextgap(gap)) {
        for(int i = 0; i + gap < n; i ++) {
            if(v1[i] > v1[i + gap]) {
                swap(v1[i], v1[i + gap]);
            }
        }
    }
    
    // sort second vector with shell sort
    for(int gap = nextgap(m); gap > 0; gap = nextgap(gap)) {
        for(int i = 0; i + gap < m; i ++) {
            if(v2[i] > v2[i + gap]) {
                swap(v2[i], v2[i + gap]);
            }
        }
    }
    
    for(auto x: v1) {
        cout << x << " ";
    }
    for(auto x: v2) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t --) {
      solve();
  }
  return 0;
}