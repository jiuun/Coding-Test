#include <iostream>

using namespace std;

int main()
{
    {

    }
}

// https://school.programmers.co.kr/learn/courses/30/lessons/12931
int solution12931(int n)
{
    // 자릿수 더하기
    int temp = n;
    int sum = 0;

    while (temp > 0)
    {
        sum += temp % 10;

        temp /= 10;
    }

    return sum;
}

