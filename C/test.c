#include <stdio.h>
#include <string.h>

int main() {
    int arr[2][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}
    };
    /* printf("%ld\n", arr); */
    printf("%ld\n", &arr);
    printf("%ld\n", arr + 1);

    int (*p)[2][4] = &arr;
    printf("%ld\n", p);

    return 0;
}

