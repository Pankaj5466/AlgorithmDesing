#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArray( vector<int>& arr, vector<int>& result, int low, int mid, int high)
{
    int i=low,j=mid+1;
    int k=low;

    while(i<=mid && j<=high)
    {
        if(arr[i] > arr[j])
            result[k++] = arr[i++];
        else 
            result[k++] = arr[j++];
    }

    while(i<=mid)
        result[k++] = arr[i++];
    while(j<=high)
        result[k++] = arr[j++];

    
    //Update main array
    for(int i=low;i<=high;i++)
        arr[i] = result[i];
}
void mergeSort(int low, int high, vector<int>& arr, vector<int>& result)
{
    if(low >= high)
        return;
    printf("%d,%d\n",low,high);
    int mid = (high-low)/2 + low;
    //int mid = (high+low)/2;
    mergeSort(low,mid,arr,result);
    mergeSort(mid+1,high,arr,result);

    mergeSortedArray(arr,result,low,mid,high);

    printf("SortedArry from %d->%d\n",low,high);
    for(int i=low;i<=high;i++)
        printf("%d ",result[i]);
    printf("\n");
}

int main()
{
    vector<int> arr{4,6,2,1,6,8,78,90,54,3};
    int size = arr.size();
    vector<int> result(size);

    printf("Do Merge Sort\n");
    mergeSort(0,size-1,arr,result);

    printf("Result after sorting is\n");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);

    return 0;
}