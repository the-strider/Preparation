/*input
12
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  while(n) {
  	cnt ++;
  	n = (n & (n << 1));
  }
  cout << cnt;
  return 0;
}