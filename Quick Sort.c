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
void quicksort(int a[],int f,int l)
{
	int i,j,piv,tem;
	piv=f;
	i=f;
	j=l;
	if(f<l)
	{
		while(i<j)
		{
			while(a[i]<=a[piv]&&i<l)
			{
				i++;
			}
			while(a[j]>a[piv])
			{
				j--;
			}
			if(i<j)
			{
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;
			}
		}
		tem=a[piv];
		a[piv]=a[j];
		a[j]=tem;
		quicksort(a,f,j-1);
		quicksort(a,j+1,l);
	}
}