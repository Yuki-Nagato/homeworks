#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, size_t len, size_t first) {
    size_t half = len >> 1, mid = first + half;
    vector<int> l(a.begin() + first, a.begin() + first + half), r(a.begin() + mid, a.begin() + first + len);
    vector<int>::iterator it = a.begin() + first,
                          end = a.begin() + first + len,
                          pl = l.begin(),
                          pr = r.begin();
    for (; it != end; ++it) {
        if (pl == l.end())
            *it = *pr++;
        else if (pr == r.end())
            *it = *pl++;
        else if (*pl < *pr)
            *it = *pl++;
        else
            *it = *pr++;
    }
}

void mergeSort(vector<int> &a, size_t len, size_t first = 0) {
    if (len > 1) {
        size_t half = len >> 1, mid = first + half;
        mergeSort(a, half, first);
        mergeSort(a, len - half, mid);
        merge(a, len, first);
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
        mergeSort(arr, n);
        cout << "排序后" << endl;
        for (int t : arr) {
            cout << t << ' ';
        }
        cout << endl;
    }
}
