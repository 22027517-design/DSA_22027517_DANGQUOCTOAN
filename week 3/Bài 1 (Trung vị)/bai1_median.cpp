#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 != 0) {
        return arr[n / 2];
    } else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

int main() {
    vector<int> arr = {7, 2, 5, 1, 9, 3, 8};
    cout << "Mang ban dau: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Trung vi la: " << findMedian(arr) << endl;
    return 0;
}