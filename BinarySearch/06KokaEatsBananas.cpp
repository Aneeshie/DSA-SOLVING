#include <bits/stdc++.h>

using namespace std;

long long  func(vector<int> &arr, int k){
        long long totalHours = 0;
        for(int i = 0; i < arr.size(); i++){
            totalHours += ceil(double(arr[i]) / k);
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int> &arr, int h){
        int maxi = *max_element(arr.begin(), arr.end());
        int l = 1, e = maxi, ans = INT_MAX;
        while(l <= e){
            int mid = l + (e-l)/2;

            long long reqTime = func(arr,mid);

            if(reqTime <= h){
                ans = min(ans,mid);
                e = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
