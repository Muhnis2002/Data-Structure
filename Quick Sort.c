 /*Muhammed Muhnis T K
  Quick Sort
  JEC21CS083*/
#include<stdio.h>
void quicksort(int a[],int f,int l);
int main()
{
	int i,count,a[100];
	printf("Enter the limit : ");
	scanf("%d",&count);
	for(i=0;i<count;++i)
	{
		printf("Enter the %d th Element of the Array : ",i+1);
		scanf("%d",&a[i]);
	}
	quicksort(a,0,count-1);
	printf("The Sorted Array is : ");
	for(int m=0;m<count;++m)
	{
		printf("%d  ",a[m]);
	}
	return 0;
}