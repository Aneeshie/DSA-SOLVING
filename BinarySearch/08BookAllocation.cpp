#include <bits/stdc++.h>

using namespace std;


bool isPossible(vector<int> &arr, int k, int mid){
    int studentCount = 0,currentPages = 0, maxOfThosePages = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > mid){
            return false;
        }

        if(currentPages + arr[i] > mid){
            studentCount++;
            if(studentCount > k){
                return false;
            }
            currentPages = arr[i];
        }else{     
         currentPages += arr[i];
        }

    }
    return true;

}

int allocateBooks(vector<int> &arr, int k){
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = INT_MAX;

    while(s<=e){
        int mid = s + (e-s)/2;

        if(isPossible(arr,k,mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return ans;



}

int main(){
    vector<int> arr = {12,34,67,90};
    int k = 2;

    cout << allocateBooks(arr,k) << endl;
}
