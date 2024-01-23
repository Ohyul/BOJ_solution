#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        double n1, m1, n2, m2;
        scanf("%lf %lf %lf %lf", &n1, &m1, &n2, &m2);

        double temp = 1;
        for (int i = 0; i <= m1; i++)
            temp = temp * (n1 + 1 - i) / (n1 + n2 + 2 - i);

        double ans = temp;
        for (int i = 1; i <= m2; i++) {
            temp = temp * (m1 + i) / i * (n2 + 2 - i) / (n1 + n2 - m1 + 2 - i);
            ans += temp;
        }

        printf("%lf\n", ans);
    }

    return 0;
}
