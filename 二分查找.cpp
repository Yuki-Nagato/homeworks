#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t binarySearch(const vector<int> &a, int val) {
    size_t len = a.size(), first = 0;
    while (len) {
        size_t half = len >> 1u, mid = first + half;
        if (a[mid] < val) {
            first = mid + 1;
            len -= half + 1;
        }
        else
            len = half;
    }
    return first;
}

int main() {
    size_t n;
    while (cout << "输入线性表大小" << endl && cin >> n) {
        vector<int> a(n);
        cout << "输入" << n << "个数字" << endl;
        for (int &t : a)
            cin >> t;
        sort(a.begin(), a.end());
        cout << "排序后的线性表为" << endl;
        for (const int t : a)
            cout << t << ' ';
        cout << endl;
        cout << "输入查找次数" << endl;
        int q;
        cin >> q;
        while (q--) {
            cout << "输入要查找的数字" << endl;
            int target;
            cin >> target;
            size_t p = binarySearch(a, target);
            if (a[p] == target) {
                cout << "该元素位置为" << p + 1 << endl;
            }
            else {
                cout << "未找到该元素" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
