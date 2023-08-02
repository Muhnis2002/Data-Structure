/*Muhammed muhnis T k
  Bubble Sort
  JEC21CS083*/
#include<stdio.h>
int read(int a[],int n);
int sort(int a[],int n);
int main()
{
	int a[50],n;
	printf("Enter the limit of the array : ");
	scanf("%d",&n);
	read(a,n);
	sort(a,n);
	return 0;
}
int read(int a[],int n)
{
	for(int j=0;j<n;++j)
	{
		printf("Enter the %d th Element of the array : ",j+1);
		scanf("%d",&a[j]);
	}
	return 0;
}
int sort(int a[],int n)
{
	int t;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-i-1;++j)
		{
			if(a[j+1]<a[j])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("The Sorted array is : ");
	for(int j=0;j<n;++j)
	{
		printf("%d ",a[j]);
	}
	return 0;
}