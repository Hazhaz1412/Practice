#include <bits/stdc++.h>

using namespace std;


int main(){ 
    int n; cin >>n;
    vector<int> arr(n);
    for(int i = 0; i < n ;i++) {
        cin >> arr[i];
    }
    vector<long long> prefSum(n+1,0),prefMin(n+1,0);
    for(int i = 1; i <= n;i++) {
        prefSum[i] = prefSum[i-1]+arr[i-1];
        prefMin[i] = min(prefMin[i-1], prefSum[i]);
    }
    long long res = -10e9;
    for(int i = 1; i <=n;i++) {
        res = max(res, prefSum[i]-prefMin[i-1]);
    }
    cout << res ;
}   