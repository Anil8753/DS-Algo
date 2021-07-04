#include <iostream>

int solution(int X, int Y, int D)
{
    const int min_distance = Y - X;
    const int r = min_distance % D;
    int steps = r > 0 ? (min_distance / D) + 1 : (min_distance / D);
    return steps;
}

int main()
{
    std::cout << solution(10, 85, 30);
    return 0;
}