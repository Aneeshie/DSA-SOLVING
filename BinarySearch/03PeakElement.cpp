#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& arr){
  int s = 0, e = arr.size()-1;

  while(s < e){
    int mid = (s + e ) / 2;

    if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
    return mid;
    }

    //check if the current mid lies on positive slope part
    if(arr[mid + 1] > arr[mid]){
      s = mid + 1;
    }else {
      e = mid;
    }

  }

  return s;
}