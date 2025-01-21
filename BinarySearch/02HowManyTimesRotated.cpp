#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int numberOfTimesRotated(vector<int> &nums){
  int l = 0, h = nums.size()-1;
  int ans = INT_MAX, index =-1;
  //Oh wait its basically the index of the minimum number of the rotated sorted array.

  while(l <= h){
    int mid = (l + h) / 2;

    if(nums[l] <= nums[h]){
      if(nums[l] < ans){
        index = l;
        ans = nums[l];
      }
      break;
    }

    if(nums[l] <= nums[mid]){
      if(nums[l] < ans){
        index = l;
        ans = nums[l];
      }
      l = mid + 1;
    }else {
      if(nums[mid] < ans){
        index = mid;
        ans = nums[mid];
      }
      h = mid - 1;
    }
  }

  return index;

}