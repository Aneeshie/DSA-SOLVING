#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>&nums){
  int l = 0, h  = nums.size()-1;
  int ans = INT_MAX;

  while(l <= h){
    int mid = (l + h )/ 2;

    //if search space is already sorted
    if(nums[l] <= nums[h]){
      ans = min(ans,nums[l]);
    }

    //if left slope
    if(nums[l] <= nums[mid]){
      ans = min(ans,nums[l]);
      l = mid + 1;
    }else {
      ans = min(ans,nums[mid]); // right slope sorted

      h = mid - 1;
    }


  }

  return ans;

}
