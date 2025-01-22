#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>&stalls, int k, int mid){
  int cowCount = 1, lastPos = stalls[0];
  for(int i = 0; i < stalls.size(); i++){
    if(stalls[i] - lastPos >= mid){
      cowCount++;
      if(cowCount == k){
        return true;
      }
      lastPos = stalls[i];
    }
  }

  return false;
}

int aggCows(vector<int> &stalls, int k){
  sort(stalls.begin(), stalls.end());
  int maxi = *max_element(stalls.begin(),stalls.end());
  int s = 0,  e = maxi, ans = INT_MIN;

  while(s <= e){
    int mid = (s + e) / 2;
    if(isPossible(stalls,k,mid)){
      ans = mid;
      s = mid + 1;
    }else{
      e = mid - 1;
    }
  }
}