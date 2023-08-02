/*Muhammed Muhnis T K
  Binary Search
  JEC21CS083*/
#include<stdio.h>
int read(int a[],int n);
int search();
void sort(int a[],int n);
int main()
{
	int a[100],n,x;
	printf("Enter the Limit of array : ");
	scanf("%d",&n);
	read(a,n);
	sort(a,n);
	printf("\n");
	printf("Enter the Element to be searched in the array : ");
	scanf("%d",&x);
	search(a,n,x);
	return 0;
}
int read(int a[],int n)
{
	for(int i=0;i<n;++i)
	{
		printf("Enter the %d th Element of the array : ",i+1);
		scanf("%d",&a[i]);
	}
	return 0;
}
void sort(int a[],int n)
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
	printf("The Sorted array for performing Binary Search is : ");
	for(int j=0;j<n;++j)
	{
		printf("%d ",a[j]);
	}
}