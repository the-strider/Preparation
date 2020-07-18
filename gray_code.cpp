/*input
5
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < (1 << n); i ++) {
  	int ans = i ^ (i >> 1);
  	cout << ans << " ";
  }
  return 0;
}