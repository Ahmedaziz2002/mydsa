#include<stdio.h>

int partition(int arr[],int low, int high){
    int pivot=arr[high];//choose the last element as pivot
    int i=(low-1);//index of smaller element
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){//if arr is smaller than the pivot
            i++;//increment index of smaller element
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }//swap the pivot elements with the element at i+1
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return -1;
}

int main(){
    int arr[5]={4,5,2,1,3};
    int lenofarray=sizeof(arr)/sizeof(int);

    printf("Original array\n");
    for(int i=0;i<lenofarray;i++){
        printf("array at [%d] id %d\n",i,arr[i]);
    }

    quicksort(arr,0,lenofarray-1);

    printf("Sorted array\n");
    for(int i=0;i<lenofarray;i++){
        printf("array at [%d] is %d\n",i,arr[i]);
    }
    int key=2;
    int searchresult=search(arr,lenofarray,key);

    if(searchresult!=-1){
        printf("element %d found at index %d\n",key,searchresult);
    }else{
        printf("Element %d not found in the array\n",key);
    }
    return 0;
}