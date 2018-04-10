#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int begin, int end) {
    int pivot = a[begin];
    while (begin < end) {
        while (begin < end && a[--end] >= pivot);
        a[begin] = a[end];
        while (begin < end && a[++begin] <= pivot);
        a[end] = a[begin];
    }
    a[begin] = pivot;
    return begin;
}

void quickSort(vector<int> &a, int len, int first = 0) {
    if (len > 1) {
        int m = partition(a, first, first + len);
        quickSort(a, m - first, first);
        quickSort(a, first + len - m - 1, m + 1);
    }
}

int main() {
    size_t n;
    while (cout << "输入数据个数" << endl && cin >> n) {
        vector<int> arr(n);
        cout << "输入" << n << "个数字" << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        quickSort(arr, n);
        cout << "排序后" << endl;
        for (int t : arr) {
            cout << t << ' ';
        }
        cout << endl;
    }
    return 0;
}
