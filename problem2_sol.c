#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);
    int rem = arr[0] % k;
    for (int i = 1; i < n; i++) {
        if (arr[i] % k != rem) {
            printf("-1\n");
            return 0;
        }
    }
    int norm[n];
    for (int i = 0; i < n; i++) {
        norm[i] = (arr[i] - rem) / k;
    }

    qsort(norm, n, sizeof(int), compare);

    int median = norm[n / 2];

    int operations = 0;
    for (int i = 0; i < n; i++) {
        operations += abs(norm[i] - median);
    }

    printf("%d\n", operations);

    return 0;
}
