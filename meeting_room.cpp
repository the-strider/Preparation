/*
Sorting according to finish time of the pair
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  vector < int > v1 = {1, 3, 0, 5, 8, 5};
  vector < int > v2 = {2, 4, 6, 7, 9, 9};
  int n = v1.size();
  vector < pair < int, int > > v;
  for(int i = 0; i < n; i ++) {
    v.push_back({v2[i], v1[i]});
  }

  sort(v.begin(), v.end());

  int ans = 1;
  int last = v[0].first;
  for(int i = 1; i < n; i ++) {
    if(last < v[i].second) {
      last = v[i].first;
      ans ++;
    }
  }

  cout << ans << "\n";
  return 0;
}