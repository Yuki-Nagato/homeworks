#include<stdio.h>
int main()
{
    int p[101], i, j, k, r, t, n;
    int m[101][101];            //为了跟讲解时保持一致数组从1开始
    int s[101][101];            //记录从第i到第j个矩阵连乘的断开位置
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);      //读入p[i]的值(注意：p[0]到p[n]共n+1项)
    for (i = 1; i <= n; i++)           //初始化m[i][i]=0
        m[i][i] = 0;
    for (r = 1; r<n; r++)            //r为i、j相差的值
        for (i = 1; i<n; i++)        //i为行
        {
            j = i + r;              //j为列
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];    //给m[i][j]赋初值
            s[i][j] = i;
            for (k = i + 1; k<j; k++)
            {
                t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t<m[i][j])
                {
                    m[i][j] = t;                //m[i][j]取最小值
                    s[i][j] = k;
                }
            }
        }
    printf("%d", m[1][n]);
}
