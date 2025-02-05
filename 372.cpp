class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        return temp(a % MOD, b, b.size() - 1, MOD);
    }
    int temp(int a, vector<int>& b, int idx, int mod) {
        if (idx < 0) return 1;
        int lastDigit = b[idx];
        
        int part1 = myPow(a, lastDigit, mod);

        int part2 = myPow(temp(a, b, idx - 1, mod), 10, mod);



        return (part1 * part2) % mod;
    }
    int myPow(int x, int n, int mod) {
        if (n == 0) return 1;
        x %= mod;
        int result = 1;
        // for (int i = 0; i < n-1; ++i) {
        //     result = (result * x) % mod;
        // }
        for (int i = 0; i < n; ++i) {
            result = (result * x) % mod;
        }
        return result;
    }
};