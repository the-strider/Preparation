/*input
2147483647

Idea = shell sort like
Since for 32 bit number, update n by dividing it to all power 2 less than 32 after this all place will be set
increment this place it will point to next power of 2 so to get the current powr of 2 divide it by 2
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;

  for(ll x: {1, 2, 4, 8, 16}) {
    n |= (n >> x);
  }

  n ++;	// increment
  n >>= 1; // divide by 2
  cout << n;
  return 0;
}