#include <cstdio>
#include <list>

struct Movement {
    int s, t;
    bool operator < (const Movement& b) const {
        return s < b.s;
    }
};

int m;
std::list<Movement> st;

int main() {
    scanf("%*d%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        st.push_front({ a,b });
    }
    st.sort();
    int ans;
    for (ans = 0; !st.empty(); ans++) {
        int at = 0;
        for (auto it = st.begin(); it != st.end();) {
            if (it->s >= at) {
                at = it->t;
                it = st.erase(it);
            }
            else
                ++it;
        }
    }
    printf("%d\n", ans);
    return 0;
}
