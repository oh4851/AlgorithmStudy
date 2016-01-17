#include <stdio.h>
#include <stdlib.h>

typedef struct pt {
    int x;
    int y;
} point;

int getLength(point s, point e) {
    return abs(s.x - e.x) + abs(s.y - e.y);
}

int main(void) {
    int i, j, ans, n, min, minI, len, check[10];
    point map, now, karel, beep[10];

    ans = 0;

    scanf("%d %d", &map.x, &map.y);
    scanf("%d %d", &karel.x, &karel.y);
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d", &beep[i].x, &beep[i].y);
    }

    now = karel;
    for (i=0; i<n; i++) {
        min = 100;
        for (j=0; j<n; j++) {
            len = getLength(now, beep[j]);
            if (len < min && !check[j]) {
                min = len;
                minI = j;
            }
        }
        ans += min;
        check[minI] = 1;
        now = beep[minI];
        printf("%d %d -- %d\n", now.x, now.y, ans);
    }
    ans += getLength(now, karel);

    printf("The shortest path has length %d\n", ans);

    return 0;
}
