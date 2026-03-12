class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int left = 1;
        int right = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            right = max(right, nums[i]);
        }

        while(left < right)
        {
            int mid = (left + right) / 2;

            long long operations = 0;

            for(int i = 0; i < nums.size(); i++)
            {
                operations += (nums[i] - 1) / mid;
            }

            if(operations > maxOperations)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};