class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high, int& cnt) {
        int left = low, right = mid + 1,j=right;
        vector<int> temp;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }
        while (left <= mid && right <= high) {
            if (arr[left] > arr[right]) {
                temp.push_back(arr[right]);
                right++;
            } else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void mergesort(vector<int>& arr, int low, int high, int& cnt) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid, cnt);
        mergesort(arr, mid + 1, high, cnt);
        merge(arr, low, mid, high, cnt);
    }
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        mergesort(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};