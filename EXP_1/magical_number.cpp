class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        
        long long MOD = 1e9 + 7;
        long long left = 1, right = 1LL * n * min(a, b);
        
        long long lcmVal = (1LL * a * b) / gcd(a, b);

        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            long long count = (mid / a) + (mid / b) - (mid / lcmVal);
            
            if (count < n) 
                left = mid + 1;
            else 
                right = mid;
        }
        
        return left % MOD;
    }
};