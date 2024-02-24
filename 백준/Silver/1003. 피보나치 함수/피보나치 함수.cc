#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    int fibo[42][2] = { 1, 0, 0, 1 };
    for (int i = 2; i <= 40; ++i) {
        fibo[i][0] = fibo[i - 2][0] + fibo[i - 1][0];
        fibo[i][1] = fibo[i - 2][1] + fibo[i - 1][1];
    }
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", fibo[n][0], fibo[n][1]);
        //printf("%d %d\n", fibonacci0(n), fibonacci1(n));
    }
}