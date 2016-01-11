#include <stdio.h>

#define WEIGHT_LIMIT 300

int getBinaryPosition(int value, int position) {
    int i;
    for (i=0; i<position; i++) {
        value = value >> 1;
    }
    return value & 0x00000001;
}

void mergeSort(int *data, int n) {
    int i, j, mid, now;
    int temp[30];
    for (i=0; i<n; i++) {
        temp[i] = data[i];
    }
    mid = n/2;
    // left(insertion)
    for (i=1; i<mid; i++) {
        now = temp[i];
        j = i-1;
        while ((j>=0) && (temp[j] < now)) {
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = now;
    }
    // right(insertion)
    for (i=mid+1; i<n; i++) {
        now = temp[i];
        j = i-1;
        while ((j>=mid) && (temp[j] < now)) {
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = now;
    }
    // merge
    i = 0;
    j = mid;
    now = 0;

    while (i < mid && j < n) {
        if (temp[i] >= temp[j]) *(data+now++) = *(temp+i++);
        else data[now++] = temp[j++];
    }
    if (i < mid) {
        while (i < mid) {
            data[now++] = temp[i++];
        }
    }
    else if (j < n) {
        while (j < n) {
            data[now++] = temp[j++];
        }
    }
}

int main(void) {
    int i, j, n, sum, ans, pow, cnt;  // 1 <= n <= 30
    int weights[30];

    cnt = 0;
    sum = 0;

    // data input
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &weights[i]);
        sum += weights[i];
    }
    if (sum > WEIGHT_LIMIT) {
        printf("impossible\n");
        return 0;
    }
    if (sum % 2 != 0) {
        printf("impossible\n");
        return 0;
    }

    // get half of sum
    ans = sum / 2;

    // merge sort
    mergeSort(weights, n);

    // get power of weights length
    pow = 1;
    for (i=0; i<n; i++) pow *= 2;

    // find answer
    for (i=0; i<pow; i++) {
        sum = 0;
        for (j=0; j<n; j++) {
            sum += (weights[j] * getBinaryPosition(i, n-1-j));
            if (sum > ans) break;
        }
        if (sum == ans) cnt++;
    }
    printf("%d\n", cnt);
    
    return 0;
}
