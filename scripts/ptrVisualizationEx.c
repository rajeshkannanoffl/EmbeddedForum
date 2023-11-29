#include <stdio.h>
#include <stdlib.h>

int main()
{
    char   c;
    int    i;
    char*  cptr;
    int*   iptr;
    int*   iptr_malloc, *iptr_io;
    int**  iptrptr;
    
    c = 32;
    i = 2140000000;
    cptr = &c;
    iptr = &i;
    iptr_malloc = (int *) malloc(sizeof(int)*1);
    *iptr_malloc = 777;
    iptr_io = (int *) 0xffff12345678abcd;
    iptrptr = &iptr;
    
    printf("content of variable c = %d \n",c);
    printf("Adress of variable c = %p \n",&c);

    printf("content of variable i = %d \n",i);
    printf("Adress of variable i = %p \n",&i);

    printf("content of variable cptr = %p \n",cptr);
    printf("Adress of variable cptr = %p \n",&cptr);
    printf("content at memory location pointed by variable cptr %d \n",*cptr);

    printf("content of variable iptr = %p \n", iptr);
    printf("Adress of variable iptr = %p \n", &iptr);
    printf("content at memory location pointed by variable iptr %d \n", *iptr);
    
    printf("content of variable iptr_malloc = %p \n", iptr_malloc);
    printf("Adress of variable iptr_malloc = %p \n", &iptr_malloc);
    printf("content at memory location pointed by variable iptr_malloc %d \n", *iptr_malloc);

    printf("content of variable iptr_io = %p \n", iptr_io);
    printf("Adress of variable iptr_io = %p \n", &iptr_io);
    
    printf("content of variable iptrptr = %p \n", iptrptr);
    printf("Adress of variable iptrptr = %p \n", &iptrptr);
    printf("content at memory location pointed by variable iptrptr %p \n", *iptrptr);
    return 0;
}