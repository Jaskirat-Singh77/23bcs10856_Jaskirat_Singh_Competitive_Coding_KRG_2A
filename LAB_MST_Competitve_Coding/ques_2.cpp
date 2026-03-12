class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        vector<int> bit(32, 0);

        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                if (x & (1 << i)) {
                    bit[i]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int j = 0; j < 32; j++) {
                if (bit[j] > 0) {
                    num += (1LL << j);
                    bit[j]--;
                }
            }

            ans = (ans + (num * num) % mod) % mod;
        }

        return ans;
    }
};