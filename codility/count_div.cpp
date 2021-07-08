#include <iostream>

/*
Write a function:
int solution(int A, int B, int K);
that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
{ i : A ≤ i ≤ B, i mod K = 0 }
For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:
A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B.
*/
int solution(int A, int B, int K)
{
    int r = (A % K);
    int start = (r == 0) ? A : (A + (K - (A % K)));
    std::cout << start << std::endl;

    int r2 = B % K;
    int end = (r2 == 0) ? B : (B - r2);
    std::cout << end << std::endl;

    return ((end - start) / K) + 1;
}

int main()
{
  //  std::cout << solution(6, 11, 2) << std::endl; // 6,8,10 = 3
  //  std::cout << solution(5, 11, 3) << std::endl; // 6,9 = 2
    // std::cout << solution(6, 6, 2) << std::endl;   // 1
    // std::cout << solution(0, 1, 11) << std::endl;  // 0
    // std::cout << solution(2, 3, 11) << std::endl;  // 0
     std::cout << solution(10, 10, 5) << std::endl; // 0
     std::cout << solution(0, 0, 11) << std::endl;  // 1
    return 0;
}