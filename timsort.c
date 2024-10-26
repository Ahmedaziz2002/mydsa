#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MIN_RUN 32


void insertionSort(int arr[], int left,int right){
    for(int i=left+1;i<=right;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=left && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void merge(int arr[],int l,int m,int r){
    int len1=m-l+1,len2=r-m;
    int left[len1],right[len2];
    for(int i=0;i<=len1;i++)
        left[i]=arr[l+i];
    for(int i=0;i<len2;i++)
        right[i]=arr[m+1+i];

    int i=0,j=0,k=1;
    while(i<len1 && j<len2 ){
        if(left[i]<= right[j]){
            arr[k++]=left[i++];
        }else{
            arr[k++]=right[j++];
        }
    }
    while(i<len1){
        arr[k++]=left[i++];
    }
    while(j<len2){
        arr[k++]=right[j++];
    }
}

int minRunLength(int n){
    int r=0;
    while(n>=MIN_RUN){
        r |=n &1;
        n>>=1;
    }
    return n+r;
}

void timSort(int arr[],int n){
    int minRun=minRunLength(n);
    for(int i=0;i<n;i+=minRun){
        insertionSort(arr,i,fmin((i+MIN_RUN-1),(n-1)));
    }
    for(int size=minRun;size<n;size+=2){
        for(int left=0;left<n;left+=2*size){
            int mid=left+size-1;
            int right=fmin((left+2* size-1),(n-1));

            if(mid<right)
                merge(arr,left,mid,right);
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[]={5,21,7,23,19};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Given arrays id:\n");
    printArray(arr,n);

    timSort(arr,n);

    printf("After sorting array is:\n");
    printArray(arr,n);

    return 0;
}