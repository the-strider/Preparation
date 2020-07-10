/*input
1
4
3
14
2 4 3 4 2 1 3 2 3 4 1 3 1 3 4 1 4 1 3 2 2 4 2 3 2 4 4 1
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 55;
vector < int > v[N];
int color[N];
int n, m;

bool safe(int s, int col)
{
  for(auto x: v[s]) {
    if(color[x] and color[x] == col) return false;
  }
  return true;
}

bool func(int s)
{
  if(s == n + 1) {
    return true;
  }
  bool res = 0;
  for(int i = 1; i <= m; i ++) {
      if(safe(s, i)) {
        color[s] = i;
        res |= func(s + 1);
      }
      if(res) break;
  }
  color[s] = 0;
  return res;
}

void solve()
{
  int edge;
  cin >> n >> m >> edge;
  for(int i = 0; i < edge; i ++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  cout << func(1) << "\n";

  for(int i = 0; i < N; i ++) {
    v[i].clear();
    color[i] = 0;
  }    
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