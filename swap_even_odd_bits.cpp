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
  int even = n & 0x0AAAAAAAA;
  int odd = n & 0x055555555;

  even >>= 1;
  odd <<= 1;
  cout << (even | odd);
  return 0;
}