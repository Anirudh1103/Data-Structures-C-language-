#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[10],n,i,low,high,pos,key;
    int binsearch(int a[10],int key,int low, int high);
    printf("Enter the number of elements to be inserted\n");
    scanf("%d",&n);
    printf("Enter the %d elements in sorted form\n",n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter the key element to be searched\n");
    scanf("%d",&key);
    low=0;
    high = n-1;
    pos=binsearch(a,key,low,high);
    if(pos == -1)
    printf("Element %d not found\n",key);
    else
    printf("Element %d fount at pos %d",key,pos+1);
}
int binsearch(int a[10],int key,int low, int high)
{
    int mid;
    if(low>high)
    return -1;
    else
    {
        mid = (low+high)/2;
        return (key==a[mid]?mid:key<a[mid]?binsearch(a,key,low,mid-1):binsearch(a,key,high,mid+1));
    }
}