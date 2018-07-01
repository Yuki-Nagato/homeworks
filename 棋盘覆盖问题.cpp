#include <cstdio>

char ans[1024][1024];

inline char itoc(int i) {
    return i % 10 + '0';
}

int time;

void solve(int x, int y, int l, int bx, int by) {
    if (l == 1) return;
    int hl = (l >> 1);

#define TL x,y,hl,x+hl-1,y+hl-1
#define TR x,y+hl,hl,x+hl-1,y+hl
#define BL x+hl,y,hl,x+hl,y+hl-1
#define BR x+hl,y+hl,hl,x+hl,y+hl

    if (bx < x + hl) { // top
        if (by < y + hl) { // left
            solve(x, y, hl, bx, by);
            ans[x + hl][y + hl] = ans[x + hl][y + hl - 1] = ans[x + hl - 1][y + hl] = itoc(time++);
            solve(TR);
            solve(BL);
            solve(BR);
        }
        else { // right
            solve(x, y + hl, hl, bx, by);
            ans[x + hl][y + hl] = ans[x + hl][y + hl - 1] = ans[x + hl - 1][y + hl - 1] = itoc(time++);
            solve(TL);
            solve(BL);
            solve(BR);
        }
    }
    else { // bottom
        if (by < y + hl) { // left
            solve(x + hl, y, hl, bx, by);
            ans[x + hl][y + hl] = ans[x + hl - 1][y + hl] = ans[x + hl - 1][y + hl - 1] = itoc(time++);
            solve(TL);
            solve(TR);
            solve(BR);
        }
        else { // right
            solve(x + hl, y + hl, hl, bx, by);
            ans[x + hl - 1][y + hl - 1] = ans[x + hl][y + hl - 1] = ans[x + hl - 1][y + hl] = itoc(time++);
            solve(TL);
            solve(TR);
            solve(BL);
        }
    }
}

int main() {
    puts("输入k (1<=k<=10)");
    int k;
    scanf("%d", &k);
    int n = (1 << k);
    printf("棋盘大小为%d*%d\n", n, n);
    puts("输入特殊格子的行和列");
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    ans[x][y] = 'x';
    solve(0, 0, n, x, y);
    puts("结果如下（相邻的相同数字表示连在一起）");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %c", ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
