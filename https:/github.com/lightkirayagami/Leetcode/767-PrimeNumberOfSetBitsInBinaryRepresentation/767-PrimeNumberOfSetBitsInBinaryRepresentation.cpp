// Last updated: 27/04/2026, 21:47:14
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for (int i = left; i <= right; i++) {
            if (isprime(i) == true) {
                ans++;
            }
        }
        return ans;
    }

    bool isprime(int x) {
        int count = 0;
        while (x != 0) {
            x = x & (x - 1);
            count++;
        }
        int cnt = 0;

        if (count <= 1)
            return false;
        else {

            for (int i = 2; i * i <= count; i++) {
                if (count % i == 0)
                    cnt++;
            }

            // If n is divisible by more than 2
            // numbers then it is not prime
            if (cnt > 0)
                return false;

            // else it is prime
            else
                return true;
        }
    }
};