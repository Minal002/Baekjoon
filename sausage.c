#include <stdio.h>

int gcd(int a, int b) { // 최대공약수
    return b ? gcd(b, a % b) : a; // a가 b로 나눠 떨어지지 않으면 b를(a에 대입하고) 다시 나머지로 나눔
}

int main(void) {
    int n, m, result;
    scanf("%d %d", &n, &m);

    if (n % m == 0) result = 0; // 나누어 떨어지면 칼질 횟수는 0번
    else {
        result = m - gcd(n, m); // 횟수는 M - (최대공약수)
    }

    printf("%d\n", result);
}