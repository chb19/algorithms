// Functional binary search for functions: Integer -> bool
//   left, right should be Integers (left < right)
//   func should be monotonically increasing unary function that takes Integer, and returns bool
//     This can either be a function pointer or a function object
//   Returns Integer x in range [left, right) such that func(x) is false and func(x + 1) true
//   Time Complexity: O(log(right - left))
template <typename T, typename Func>
T fbinary_search(T left, T right, Func func)
{
    while (left < right - 1)
    {
        T mid = left + (right - left) / 2;
        if (func(mid))
            right = mid;
        else
            left = mid;
    }
    return left; // return right to get x such that func(x) is true and func(x - 1) is false
}