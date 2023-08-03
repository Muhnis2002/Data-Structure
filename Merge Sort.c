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
int mergesort(int a[],int f,int l)
{
	int m;
	if(f<l)
	{
		m=(f+l)/2;
		mergesort(a,f,m);
		mergesort(a,m+1,l);
		merge(a,f,m,l);
	}
	return 0;
}
int merge(int a[],int f,int m,int l)
{
	int i,j,k,b[25];
	for(i=f,j=m+1,k=f;i<=m&&j<=l;++k)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i++];
		}
		else
		{
			b[k]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=l)
	{
		b[k++]=a[j++];
	}
	for(k=f;k<=l;++k)
	{
		a[k]=b[k];
	}
	return 0;
}