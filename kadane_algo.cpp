#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector < ll > v(n);
	
	for(auto &x: v) {
		cin >> x;
	}

	ll ans = v[0];
	ll sum = v[0];

	for(int i = 1; i < n; i ++) {
		sum = max(v[i], v[i] + sum);
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t --) {
  	solve();
  }
  return 0;
}