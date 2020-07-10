/*input
11
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ll a;
  cin >> a;
  if(a < 0) {
    a = -a;
  }

  ll ans = 0;
  for(ll i = 31; i >= 0; i --) {
    if(a & (1LL << i)) {
      ans += (a << i);
    }
  }
  cout << ans;
  return 0;
}