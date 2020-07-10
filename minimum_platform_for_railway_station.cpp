/*input
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  int t;
  cin >> t;
  while(t --) {
    int n;
    cin >> n;
    vector < string > v1(n);
    vector < string > v2(n);
    for(auto &x: v1) {
      cin >> x;
    }

    for(auto &x: v2) {
      cin >> x;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = 1;
    int cnt = 1;
    int i = 1, j = 0;

    while(i < n and j < n) {Wq
      if(v1[i] <= v2[j]) {
        cnt ++;
        i ++;
      } else {
        cnt --;
        j ++;
      }
      ans = max(ans,cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}