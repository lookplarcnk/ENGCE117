#include <stdio.h> 
#include <conio.h>

main() 
{ 
    int a,b,i; 
    void swap(int *p,int *q); 
    int *p, *q; p = &a; q = &b;

    printf("Enter two number A and B : "); 
    scanf("%d%d",&a,&b);
    
    for(i=0;i<35;i++)
    printf("_");printf("\n\n");
    
    printf("Before Swap : %d\tB = %d\n",a,b);
    
    for(i=0;i<35;i++) printf("_");
    printf("\n\n");
    
    for(i=0;i<35;i++)
    printf("_");printf("\n\n");
    
    swap(p,q); for(i=0;i<35;i++)
    printf("_");printf("\n\n");
    
    getch();
    return 0; 
}

    /* Swap Operations */

    void swap(int *p, int *q) 
    {
        int temp = 0; temp = *p;
        *p = *q;
        *q = temp;
        printf("After Swap : A = %dtB = %d\n",*p,*q);
    }