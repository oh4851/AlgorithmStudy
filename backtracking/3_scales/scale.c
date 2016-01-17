#include <stdio.h>
#include <stdlib.h>

#define WEIGHT_LIMIT 300

typedef struct nd {
    int sum;
    int count;
    nd *pt;
} node;

void push(int sum, int count) {
}

node pop() {
}

int main(void) {
    int i, j, n, sum, ans, cnt;  // 1 <= n <= 30
    int weights[30];

    cnt = 0;
    ans = 0;

    // data input
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &weights[i]);
        ans += weights[i];
    }
    if ((ans > WEIGHT_LIMIT) || (ans % 2 != 0)) {
        printf("impossible\n");
        return 0;
    }

    // get half of sum
    ans = ans >> 1;

    // get power of weights length
    pow = 1;
    for (i=0; i<n; i++) pow *= 2;

    // find answer
    for (i=0; i<pow; i++) {
        sum = 0;
        for (j=0; j<n; j++) {
            if (getBinaryPosition(i, n-1-j)) sum += weights[j];
            if (sum > ans) break;
        }
        if (sum == ans) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
