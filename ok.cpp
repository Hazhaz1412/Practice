#include <iostream>

using namespace std;

int N;
long long ans = 0;
bool cot[14], cheo1[28], cheo2[28];
void quaylai(int row) {
    if (row == N) {
        ans++;
        return;
    }

    for (int c = 0; c < N; c++) {
        if (!cot[c] && !cheo1[row - c + N] && !cheo2[row + c]) {
            cot[c] = cheo1[row - c + N] = cheo2[row + c] = true;
            quaylai(row + 1);
            cot[c] = cheo1[row - c  + N] = cheo2[row + c] = false;
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == 2 || N == 3) {
            cout << 0 << endl;
            continue;
        }
        quaylai(0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
