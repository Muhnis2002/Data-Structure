 /*Muhammed Muhnis T K
  Sorting an array using Merge Sort Technique
  JEC21CS083*/
#include<stdio.h>
int read(int a[],int l);
int print(int a[],int l);
int mergesort(int a[],int f,int l);
int merge(int a[],int f,int m,int l);
int main()
{
	int a[25],n;
	printf("Enter the limit of array : ");
	scanf("%d",&n);
	read(a,n);
	printf("The Unsorted array is : ");
	print(a,n);
	mergesort(a,0,n-1);
	printf("\nThe  Sorted  array is : ");
	print(a,n);
	return 0;
}
int read(int a[],int l)
{
	for(int i=0;i<l;++i)
	{
		printf("Enter the %d th Element of the array : ",i+1);
		scanf("%d",&a[i]);
	}
	return 0;
}
int print(int a[],int l)
{
	for(int i=0;i<l;++i)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}