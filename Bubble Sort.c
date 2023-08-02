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