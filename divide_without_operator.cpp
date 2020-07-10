/*input
11 3

representing quotient in terms of binary
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll dividend = 0, divisor = 0;
  cin >> dividend >> divisor;

  if(divisor == 0) {
    cout << "Not Possible";
    return 0;
  }

  int sign = ((divisor < 0) ^ (dividend < 0)) ? 1: 0;

  ll quotient = 0, temp = 0;
  for(ll i = 32; i >= 0; i --) {
    if((temp + (divisor << i)) <= dividend) {
      temp += (divisor << i);
      quotient |= (1LL << i);
    }
  }
  ll rem = dividend - temp;
  cout << quotient << " " << rem;
  return 0;
}