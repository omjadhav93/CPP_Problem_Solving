#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMinMax(vector<int> &arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }

    int mid = (low + high) / 2;

    auto left = findMinMax(arr, low, mid);
    auto right = findMinMax(arr, mid + 1, high);

    int finalMin = min(left.first, right.first);
    int finalMax = max(left.second, right.second);

    return {finalMin, finalMax};
}

int main() {
    vector<int> arr = {5, 2, 8, 7, 1, 9};

    auto result = findMinMax(arr, 0, arr.size() - 1);

    cout << "Min = " << result.first << endl;
    cout << "Max = " << result.second << endl;

    return 0;
}
