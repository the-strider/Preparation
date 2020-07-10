#include <bits/stdc++.h>

using namespace std;
int main() {
  int t;
  cin >> t;
  while(t --) {
      int n;
      cin >> n;
      vector < vector < int > > v;
      for(int i = 0; i < n; i ++) {
          int a, b, c;
          cin >> a >> b >> c;
          v.push_back({b, c});
      }

      sort(v.begin(), v.end());

      priority_queue < int, vector < int >, greater < int > > pq;
      int ans = v[0][1];
      pq.push(v[0][1]);

      for(int i = 1; i < n; i ++) {
        if(pq.size() < v[i][0]) {
          pq.push(v[i][1]);
          ans += v[i][1];
        } else if(v[i][0] == pq.size()) {
          if(v[i][1] > pq.top()) {
            ans -= pq.top();
            pq.pop();
            ans += v[i][1];
            pq.push(v[i][1]);
          }
        }
      }
      cout << pq.size() << " " << ans << "\n";
  }
  return 0;
}