#include <cstdio>

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    int* dis = new int[k + 1];
    for (int i = 0; i < k + 1; i++) {
        scanf("%d", dis + i);
    }
    int ans = 0, rm = n;
    for (int i = 0; i < k + 1; i++) {
        if (dis[i] > n) {
            puts("no solution");
            return 0;
        }
        if (rm < dis[i]) {
            ans++;
            printf("在第%d站加了油\n", i);
            rm = n;
        }
        rm -= dis[i];
    }
    printf("%d\n", ans);
    return 0;
}
