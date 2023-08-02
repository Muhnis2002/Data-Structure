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