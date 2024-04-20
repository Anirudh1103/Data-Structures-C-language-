#include<stdio.h>
#include<stdlib.h>
int c;
void main()
{
    int n;
    void toh(int,char,char,char);
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    toh(n,'A','c','B');
    printf("Total moves = %d",c);
}
void toh(int n,char s,char d,char a)
{
    if(n==1)
    {
        printf("\nMove disk %d from peg %c to peg %c\n",n,s,d);
        c++;
        return;
    }
    toh(n-1,s,a,d);
    printf("\nMove disk %d from peg %c to peg %c\n",n,s,d);
        c++;
    toh(n-1,a,s,d);
}