#include <stdio.h>
#include <stdlib.h>

void m_malloc(int **p) {
    *p = malloc(4);
}

int main(void) {

    /* int arr[2][4] = { */
    /*     {1, 2, 3, 4}, */ 
    /*     {2, 3, 4, 5} */
    /* }; */

    /* char *restrict str1 = "1234"; */
    /* char *restrict str2 = str1; */
    int *p = 0;
    printf("%p\n", p);
    
    m_malloc(&p);
    printf("%p\n", p);

    return 0;
}
