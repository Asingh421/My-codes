#include<stdio.h>
#include<stdlib.h>
 void swap(int *a,int *b)
  {int temp=*a;
   *a=*b;
   *b=temp;
   }
void heapify(int arr[],int n,int i)
   {int l=2*i+1,largest=i;
    int r=2*i+2;
    if(l<n&&arr[l]>arr[largest])
         largest=l;
    if(r<n&&arr[r]>arr[largest])
         largest=r;
    swap(&arr[i],&arr[largest]);
    if(largest!=i)
        heapify(arr,n,largest);

    }
void build_heap(int arr[],int n)
   {for(int i=n/2-1;i>=0;i--)
      {heapify(arr,n,i);}
   }
 void insert(int arr[],int a,int *n)
      {int temp=*n;
       arr[temp]=a;
       *n=temp+1;
       build_heap(arr,temp+1);}
int search(int arr[],int a,int i,int n)
     {int l,r;
         if(arr[i]==a)
         return i;
         if(2*i+1>=n)
            return -1;

      else
      {l=search(arr,a,2*i+1,n);
        r=search(arr,a,2*i+2,n);
        if(l<=r)
            return r;
        else
            return l;
       }
      }
  void print(int arr[],int l,int r)
      {for(int i=l;i<r;i++)
          {printf("%d ",arr[i]);}

      }
  int main()
  {int size,op;
    printf("Enter the max size of array\n");
    scanf("%d",&size);
    int arr[size];
    int n;
    printf("Enter initial no of elements\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
       {scanf("%d",&arr[i]);}
    build_heap(arr,n);
    print(arr,0,n);
    printf("\nWhat do you want to do:\npress 1 for search\npress 2 for insertion\npress 0 for exit");
    scanf("%d",&op);
    while(op!=0)
    {


    if(op==1)
      {int a;
        printf("Enter the element you want to search\n");
        scanf("%d",&a);
        int ind=search(arr,a,0,n);
        if(ind<0)
            printf("Not Found");
        else
            printf("no is at index %d",ind);
      }
      if(op==2)
        {int a;
        printf("Enter the element you want to insert\n");
        scanf("%d",&a);
        insert(arr,a,&n);
        print(arr,0,n);

        }
       printf("\nWhat do you want to do:\npress 1 for search\npress 2 for insertion\npress 0 for exit");
       scanf("%d",&op);

    }




  }








