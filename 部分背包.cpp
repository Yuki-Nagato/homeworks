#include <cstdio>
#include <vector>
#include <algorithm>

struct Item {
    double w, v;
    int id;
    bool operator< (const Item& b) const {
        return v / w > b.v / b.w;
    }
};

int main() {
    puts("输入背包大小");
    double c;
    scanf("%lf", &c);
    puts("输入物品个数");
    int n;
    scanf("%d", &n);
    std::vector<Item> item(n);
    puts("依次输入物品的重量和价值");
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &item[i-1].w, &item[i-1].v);
        item[i-1].id = i;
    }
    std::sort(item.begin(), item.end());
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double wi = std::min(item[i].w, c);
        double vi = wi * item[i].v / item[i].w;
        c -= wi;
        sum += vi;
        printf("装入物品%d，重量%f，价值%f\n", item[i].id, wi, vi);
        if (c <= 0)
            break;
    }
    printf("总价值%f\n", sum);
    return 0;
}
