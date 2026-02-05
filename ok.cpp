#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long N;
        int H;
        char C;
        cin >> N >> H >> C;

        // Giờ 12h dạng 0..11 (0 tương đương 12)
        int hour = H % 12;
        bool isPM = (C == 'P');
        int dir = 1; // 1 = cộng, -1 = trừ

        for (long long i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                dir = -dir;
            } else {
                // cộng/trừ x giờ
                hour = (hour + dir * x) % 12;
                if (hour < 0) hour += 12;

                // lật AM/PM nếu đi qua số giờ chia hết 12
                if ((x / 12) % 2 == 1) {
                    isPM = !isPM;
                }
            }
        }

        if (hour == 0) hour = 12;
        cout << hour << ' ' << (isPM ? 'P' : 'A') << '\n';
    }

    return 0;
}
