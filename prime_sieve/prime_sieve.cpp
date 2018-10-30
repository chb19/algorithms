#include "prime_sieve.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const int n = 1000;
    static bool is_prime[n];
    fill_n(is_prime, n, true);
    sieve(is_prime, n);
    int primes_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (is_prime[i])
        {
            cout << i << endl;
            primes_count++;
        }
    }
    cout << primes_count;
    return 0;
}