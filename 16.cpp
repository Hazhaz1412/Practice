#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEnergy(vector<int>& arr) {
    int n = arr.size();
    
    // First, identify all runs of zeros
    vector<int> zeroRuns;
    int currentRun = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            currentRun++;
        } else {
            if (currentRun > 0) {
                zeroRuns.push_back(currentRun);
                currentRun = 0;
            }
        }
    }
    
    // Don't forget potential zero run at the end
    if (currentRun > 0) {
        zeroRuns.push_back(currentRun);
    }
    
    // Sort runs in descending order (we want to handle largest runs first)
    sort(zeroRuns.begin(), zeroRuns.end(), greater<int>());
    
    // Count total zeros
    int totalZeros = 0;
    for (int run : zeroRuns) {
        totalZeros += run;
    }
    
    // Calculate minimum operations
    int operations = 0;
    int zerosRemoved = 0;
    
    // Use operation 1 when beneficial (when a run size > 1)
    for (int runSize : zeroRuns) {
        if (runSize > 1) {
            operations++;
            zerosRemoved += runSize;
        }
    }
    
    // Use operation 2 for remaining zeros
    operations += (totalZeros - zerosRemoved);
    
    return operations;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << minEnergy(arr) << endl;
    }
    
    return 0;
}