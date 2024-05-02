#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int maxsub(int arr[], int l, int r, int &start, int &end) {
    if (l == r) {
        start = end = l;
        return arr[l];
    }

    int m = (l + r) / 2;
    int left_start, left_end, right_start, right_end, crossing_start, crossing_end;

    int lmss = maxsub(arr, l, m, left_start, left_end);
    int rmss = maxsub(arr, m + 1, r, right_start, right_end);

    int lsum = INT_MIN, rsum = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > lsum) {
            lsum = sum;
            crossing_start = i;
        }
    }

    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > rsum) {
            rsum = sum;
            crossing_end = i;
        }
    }

    int overlapping = lsum + rsum;

    if (lmss >= rmss && lmss >= overlapping) {
        start = left_start;
        end = left_end;
        return lmss;
    } else if (rmss >= lmss && rmss >= overlapping) {
        start = right_start;
        end = right_end;
        return rmss;
    } else {
        start = crossing_start;
        end = crossing_end;
        return overlapping;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int start, end;
    int max_sum = maxsub(a, 0, n - 1, start, end);

    cout << "The maximum subarray sum is " << max_sum << endl;
    cout << "The elements of the maximum subarray are: ";
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
