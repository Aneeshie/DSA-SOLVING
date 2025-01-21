#include <bits/stdc++.h>

using namespace std;

int func(int mid, int n , int m){
  long long ans = 1;
  for(int i = 1; i <= n; i++){
    ans *= mid;
    if(ans > m) return 2;
  }
  if(ans == m) return 1;
  return 0;
}

int nthROOT(int m, int n){
  int l = 1, r = m - 1;

  while(l <= r){
    int mid = (l+r)/2;
    int midForNth = func(mid , n , m);
    if(midForNth == 2) r = mid - 1;
    else if(midForNth == 0) l = mid + 1;
    else if(midForNth == 1) return mid;
  }
}