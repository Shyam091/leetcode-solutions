#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
   
        int count = 1; 
        
        vector<char> isPrime(n, 1);
        
      
        for (long long i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
                
                
                if (i * i < n) {
                    for (long long j = i * i; j < n; j += 2 * i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        
        return count;
    }
};