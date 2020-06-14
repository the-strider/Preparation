/*
Count of subarray whose xorsum is equals to the target
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  vector < int > v(n);
  for(auto &x: v) {
    cin >> x;
  }

  unordered_map < int, int > mp;
  int xor_sum = 0;
  int ans = 0;
  mp[0] = 1;
  for(auto x: v) {
    xor_sum ^= x;
    if(mp.find(xor_sum ^ m) != mp.end()) {
        ans += mp[xor_sum ^ m];
    }
    mp[xor_sum] ++;
  }

  cout << ans << "\n";
  return 0;
}