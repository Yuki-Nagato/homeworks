#include <iostream>

int a[1000000], n;

int partition(int num[], int begin, int end) {
    int pivot = num[begin];
    while(begin<end) {
        while(begin<end && num[--end]>=pivot);
        num[begin] = num[end];
        while(begin<end && num[++begin]<=pivot);
        num[end] = num[begin];
    }
    num[begin] = pivot;
    return begin;
}

int kth_small(int num[], int len, int k) {
    int begin = 0, end = len;
    while(begin<end) {
        int pos = partition(num, begin, end);
        if(pos==k-1)
            return num[pos];
        if(pos<k-1)
            begin = pos+1;
        else
            end = pos;
    }
    return -1;
}

int main() {
    using namespace std;
    while(cout << "数据个数" << endl && cin >> n) {
        cout << "数据" << endl;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        cout << "输入k" << endl;
        int k;
        cin >> k;
        cout << "第k小的数是" << kth_small(a, n, k) << endl;
    }
    return 0;
}
