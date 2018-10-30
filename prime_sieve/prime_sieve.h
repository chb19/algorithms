// Sieve of Eratosthenes
//   is_prime is pointer to an boolean array of size n, initialized to true
//   Time complexity: O(n*log(log(n)))
void sieve(bool* is_prime, int n)
{
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (is_prime[i] and (long long)i * i < n)
        {        
            for (int j = i * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}