#include <iostream>
#include <vector>

using namespace std;

int minEnergy(vector<int>& arr) {
    int n = arr.size();
    int energy = 0;
    bool flipped;
    do {
        flipped = false;
        int bestFlip = -1;
        int bestGain = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                int zerosToLeft = 0;
                int j = i - 1;
                while (j >= 0 && arr[j] == 0) {
                    zerosToLeft++;
                    j--;
                }
                
                int zerosToRight = 0;
                j = i + 1;
                while (j < n && arr[j] == 0) {
                    zerosToRight++;
                    j++;
                }
                
                int gain = zerosToLeft + zerosToRight - 1; 
                if (gain > bestGain) {
                    bestGain = gain;
                    bestFlip = i;
                }
            }
        }
        
        if (bestGain > 0) {
            flipped = true;
            energy++;
            
            arr[bestFlip] = 0;
            int j = bestFlip - 1;
            while (j >= 0 && arr[j] == 0) {
                arr[j] = 1;
                j--;
            }
            
            j = bestFlip + 1;
            while (j < n && arr[j] == 0) {
                arr[j] = 1;
                j++;
            }
        }
    } while (flipped);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) energy++;
    }
    
    return energy;
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