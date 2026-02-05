# gen_2026.py
import random

def can_make_2026(cnt):
    target = [2,0,2,6]
    cnt = cnt[:]  # copy

    def backtrack(i):
        if i == len(target):
            return True
        d = target[i]

        # 1) dùng trực tiếp
        if cnt[d] > 0:
            cnt[d] -= 1
            if backtrack(i+1):
                cnt[d] += 1
                return True
            cnt[d] += 1

        # 2) ghép 2 chữ số a,b với a+b==d hoặc |a-b|==d
        for a in range(10):
            if cnt[a] == 0:
                continue
            cnt[a] -= 1
            for b in range(10):
                if cnt[b] == 0:
                    continue
                cnt[b] -= 1
                if a + b == d or abs(a - b) == d:
                    if backtrack(i+1):
                        cnt[b] += 1
                        cnt[a] += 1
                        return True
                cnt[b] += 1
            cnt[a] += 1
        return False

    return backtrack(0)

def generate_one(force_yes=False):
    if not force_yes:
        # counts ngẫu nhiên, giới hạn nhỏ để đa dạng
        return [random.randint(0, 5) for _ in range(10)]

    # ép tạo được 2026 (cách đơn giản)
    cnt = [random.randint(0, 3) for _ in range(10)]
    # đảm bảo 2,0,2
    if cnt[2] < 2:
        cnt[2] = 2
    if cnt[0] < 1:
        cnt[0] = 1
    # đảm bảo 6 có thể tạo: ưu tiên 5+1
    if cnt[6] + min(cnt[5], cnt[1]) == 0:
        cnt[5] += 1
        cnt[1] += 1
    return cnt

def write_io(T=1000, ensure_yes_ratio=0.5, seed=2026):
    # khống chế T ≤ 1000
    if T > 1000:
        T = 1000

    random.seed(seed)
    tests = []
    answers = []
    yes_quota = int(T * ensure_yes_ratio)

    for _ in range(yes_quota):
        cnt = generate_one(force_yes=True)
        tests.append(cnt)
        answers.append("YES" if can_make_2026(cnt[:]) else "NO")

    for _ in range(T - yes_quota):
        cnt = generate_one(force_yes=False)
        tests.append(cnt)
        answers.append("YES" if can_make_2026(cnt[:]) else "NO")

    paired = list(zip(tests, answers))
    random.shuffle(paired)
    tests, answers = zip(*paired) if paired else ([], [])

    # Ghi 1.in
    with open("4.in", "w", encoding="utf-8") as f:
        f.write(str(T) + "\n")
        for cnt in tests:
            f.write(" ".join(map(str, cnt)) + "\n")

    # Ghi 1.out
    with open("4.out", "w", encoding="utf-8") as f:
        for ans in answers:
            f.write(ans + "\n")

if __name__ == "__main__":
    # chỉnh T và tỉ lệ YES nếu cần
    write_io(T=1000, ensure_yes_ratio=0.3, seed=1412)
