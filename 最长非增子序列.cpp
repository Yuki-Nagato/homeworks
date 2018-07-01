#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    auto p = h.begin();
    for (int x : h) {
        auto q = std::upper_bound(h.begin(), p, x, std::greater<int>());
        *q = x;
        if (q == p)
            ++p;
    }
    printf("%d\n", p - h.begin());
    return 0;
}
