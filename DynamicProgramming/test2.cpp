class Solution {
  public:
    long long int merge(long long array1[], long long temp[], long long int left, long long int mid, long long int right) {
        long long int i, j, k;
        long long int count = 0;
        i = left; //i to locate first array1ay location
        j = mid; //i to locate second array1ay location
        k = left; //i to locate merged array1ay location
        while ((i <= mid - 1) && (j <= right)) {
            if (array1[i] <= array1[j]){ //when left item is less than right item
            temp[k++] = array1[i++];
            } else {
                temp[k++] = array1[j++];
                count += (mid - i); //find how many convertion is performed
            }
        }
        while (i <= mid - 1) //if first list has remaining item, add them in the list
            temp[k++] = array1[i++];
        while (j <= right) //if second list has remaining item, add them in the list
            temp[k++] = array1[j++];
        for (i=left; i <= right; i++)
            array1[i] = temp[i]; //store temp array1ay to main array1ay
        return count;
    }
    
    long long int mergeSort(long long array1[], long long temp[], long long int left, long long int right){
        long long int mid, count = 0;
        if (right > left) {
            mid = (right + left)/2; //find mid index of the array1ay
            count = mergeSort(array1, temp, left, mid); //merge sort left sub array1ay
            count += mergeSort(array1, temp, mid+1, right); //merge sort right sub array1ay
            count += merge(array1, temp, left, mid+1, right); //merge two sub array1ays
        }
        return count;
    }
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        for (long long int i = 0; i < N; i++)
            temp[i] = arr[i];
        return mergeSort(arr, temp, 0, N - 1);
    }

};