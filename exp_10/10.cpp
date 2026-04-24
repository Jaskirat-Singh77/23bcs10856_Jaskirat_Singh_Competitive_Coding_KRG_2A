#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> arr;

        // store value + original index
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, result);
        return result;
    }

    void mergeSort(vector<pair<int,int>>& arr, int left, int right, vector<int>& result) {
        if (left >= right) return;

        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, result);
        mergeSort(arr, mid + 1, right, result);
        merge(arr, left, mid, right, result);
    }

    void merge(vector<pair<int,int>>& arr, int left, int mid, int right, vector<int>& result) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightCount++;
                j++;
            } else {
                result[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            result[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }
};

int main() {
    vector<int> nums = {5, 2, 6, 1};

    Solution obj;
    vector<int> ans = obj.countSmaller(nums);

    for (int x : ans) cout << x << " ";
    // Output: 2 1 1 0

    return 0;
}