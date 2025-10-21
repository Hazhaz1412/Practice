// g++ -O2 -std=c++17 vlu_ascii3d.cpp -o vlu && ./vlu
#include <bits/stdc++.h>
using namespace std;

static const vector<string> glyph = {
"VV     VV   LL        UUU   UUU",
"VV     VV   LL        UUU   UUU",
" VV   VV    LL        UUU   UUU",
" VV   VV    LL        UUU   UUU",
"  VV VV     LL        UUU   UUU",
"  VV VV     LL        UUU   UUU",
"   VVV      LL        UUU   UUU",
"   VVV      LL        UUU   UUU",
"    V       LLLLLLLL   UUUUUUU "
};

// Ký tự theo độ “đậm” (nhạt -> đậm)
static const string ramp = " .:-=+*#%@";

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // Kích thước “màn hình ASCII”
    const int W = 160, H = 45;

    // Tham số 3D
    const float voxel = 1.0f;     // độ lớn 1 ô bitmap
    const int   thick = 8;        // số lớp extrude theo trục z
    const float zstep = 0.5f;     // khoảng cách giữa các lớp
    const float FOV   = 85.0f;    // góc nhìn
    const float PI    = 3.14159265f;
    const float f     = 1.0f / tanf((FOV*0.5f) * PI / 180.f);
    const float camZ  = 26.0f;    // đẩy mô hình ra xa camera
    const float scale = 1.9f;     // phóng to khi đưa lên màn hình

    // Tạo point cloud 3D từ bitmap + extrude
    struct P { float x,y,z; };
    vector<P> pts;
    int GH = (int)glyph.size();
    int GW = 0; for (auto &s: glyph) GW = max(GW, (int)s.size());
    float ox = -GW * 0.5f, oy = -GH * 0.5f; // tâm về (0,0)

    for (int y = 0; y < GH; ++y)
        for (int x = 0; x < (int)glyph[y].size(); ++x)
            if (glyph[y][x] != ' ') {
                for (int k = 0; k < thick; ++k)
                    pts.push_back({ (ox + x)*voxel, (oy + y)*voxel,
                                    (k - thick/2.0f)*zstep });
            }

    auto clampi = [&](int v,int lo,int hi){ return max(lo,min(hi,v)); };

    cout << "\x1b[2J\x1b[?25l"; // clear + ẩn con trỏ
    float t = 0.f;
    while (true) {
        vector<char>  scr(W*H, ' ');
        vector<float> zbuf(W*H, 1e9);

        // Quay quanh Y rồi X
        float cy = cosf(t*0.9f), sy = sinf(t*0.9f);
        float cx = cosf(t*0.5f), sx = sinf(t*0.5f);

        for (auto &p : pts) {
            // R_y
            float x1 =  cy*p.x + sy*p.z;
            float z1 = -sy*p.x + cy*p.z;
            // R_x
            float y2 =  cx*p.y - sx*z1;
            float z2 =  sx*p.y + cx*z1;

            float zc = z2 + camZ;              // về hệ toạ độ camera
            if (zc <= 0.1f) continue;

            // Chiếu phối cảnh
            float px = (x1 * f / zc) * scale;
            float py = (y2 * f / zc) * scale;

            int sx = (int)(W  * (0.5f + px * 0.5f));
            int sy = (int)(H  * (0.5f - py * 0.5f)); // dấu '-' để trục y hướng lên
            if (sx < 0 || sx >= W || sy < 0 || sy >= H) continue;

            int idx = sy*W + sx;
            if (zc < zbuf[idx]) {
                zbuf[idx] = zc;
                // gần hơn -> đậm hơn
                float d = (camZ + 6.f - zc) / 14.f;   // map tay
                int r = clampi((int)(d * (int)ramp.size()), 0, (int)ramp.size()-1);
                scr[idx] = ramp[r];
            }
        }

        // in khung
        cout << "\x1b[H";
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) cout << scr[y*W + x];
            cout << '\n';
        }
        cout << "points: " << pts.size() << "   (Ctrl+C to quit)\n";

        this_thread::sleep_for(chrono::milliseconds(16)); // ~60fps
        t += 0.03f;
    }
}
