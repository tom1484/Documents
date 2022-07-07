#include <stdio.h>
<<<<<<< HEAD
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
=======
#include <stdlib.h>

void m_malloc(int **p) {
    *p = malloc(4);
}

int main(void) {

    /* int arr[2][4] = { */
    /*     {1, 2, 3, 4}, */ 
    /*     {2, 3, 4, 5} */
    /* }; */
>>>>>>> 8d7ba71f43c0b239eb4ef7c810d2fefe8ad51368

    /* char *restrict str1 = "1234"; */
    /* char *restrict str2 = str1; */
    int *p = 0;
    printf("%p\n", p);
    
    m_malloc(&p);
    printf("%p\n", p);

    return 0;
}
