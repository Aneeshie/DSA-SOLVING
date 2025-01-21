#include <iostream>

using namespace std;

int squareRoot(int n){
  int l = 0, r = n-1;
  while(l <= r){
    int mid = (l + r) / 2;

    if(mid * mid  == n){
      return mid;
    }

    if(mid * mid > n){
      r = mid - 1;
    }else {
      l = mid + 1;
    }
  }
  return -1;
}

int main(){
  cout << squareRoot(49) << endl;
}