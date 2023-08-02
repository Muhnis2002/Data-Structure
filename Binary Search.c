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