/*input
1
84 87
78 16 94 36 87 43 50 22 63 28 91 10 64 27 41 27 73 37 12 19 68 30 83 31 63 24 68 36 30 3 23 9 70 18 94 7 12 43 30 24 22 20 85 38 99 25 16 21 14 27 92 31 57 24 63 21 97 32 6 26 85 28 37 6 47 30 14 8 25 46 83 46 15 18 35 15 44 1 88 9 77 29 89 35 4 2 55 50 33 11 77 19 40 13 27 37 95 40 96 21 35 29 68 2 98 3 18 43 53 7 2 31 87 42 66 40 45 20 41 30 32 18 98 22 82 26 10 28 68 7 98 4 87 16 7 34 20 25 29 22 33 30 4 20 71 19 9 16 41 50 97 24 19 46 47 2 22 6 80 39 65 29 42 1 94 1 35 15

*/

#include <bits/stdc++.h>

#define prec(n)     cout << fixed << setprecision(n)

using namespace std;
using ll = long long;

int main()
{
  int t;
  cin >> t;
  while(t --) {
    int n, w;
    cin >> n >> w;
    vector < pair < double, pair < int, int > > > v(n);
    for(auto &x: v) {
      cin >> x.second.first >> x.second.second;
      x.first = (x.second.first * 1.0) / (x.second.second * 1.0);
    } 

    sort(v.begin(), v.end(), greater < pair < double, pair < int, int > > > ());

    double ans = 0;
    for(int i = 0; i < n; i ++) {
      if(w == 0) break;
      int val = v[i].second.first;
      int wei = v[i].second.second;

      if(wei < w) {
        w -= wei;
        ans += val * 1.0;
      } else {
        ans += (val * 1.0) * (w * 1.0 / wei);
        w = 0;
      }
    }
    prec(2);
    cout << ans << "\n";
  }
  return 0;
}