// Quick Sort Program
#include <iostream>
#include <string>
using namespace std;

void swap(int A[], int x, int y)
{

 int tmp = A[x];

 A[x] = A[y];
 A[y] = tmp;
}

// Partition the array such that all entries <= pivot are to it's left
// all entries > pivot are to it's right
// Returns : index of the pivot 
int partition (int A[], int start_idx, int end_idx)
{
    // Start with pivotIdx = end_index
    int pivotIdx = end_idx;
    
    // partitionIdx - points to the point between the left sub-array 
    // that is <= pivot and the right array that is > pivot. The 
    // partitionIdx actually points to the first entry in the right 
    // sub-array. This makes is easy to swap this entry with the starting 
    // pivotIdx
    int partitionIdx = start_idx;
    
    // Moving index that scans through the array. This index separates 
    // the processed array [<= pivot and > pivot] from the to-be processed 
    // part of the array. Since pivot is the last element, need to scan only 
    // up to end_index -1
    // Note that partitionIdx <= i always (i leads the partition idex)
    for (int i = start_idx; i<end_idx; i++) {
      // if value is > pivot, increment i. partitionIdx stays. Essentially 
      // adds this elemnt to the right of partitionIdx
      if (A[i] > A[pivotIdx]) {
          // Do nothing - continue to process next element
      } else {
          // Need to add this to the end of left sub-array
          // For this, swap with the first element of right sub-array (=partitionIdx)
          // and then move the partitionIdx;
          swap(A, partitionIdx, i);
          partitionIdx++;
      }
    }
    
    // Now swap the pivot to the right position
    swap(A, partitionIdx, pivotIdx);
    
    // return the final pivot index
    return partitionIdx;
        
}

void quick_sort(int A[], int start_idx, int end_idx)
{
    
    // base case
    if (start_idx ==  end_idx)
        return;
    
    // Partition
    int pivot = partition (A, start_idx, end_idx);
    
    // Recursively sort left and right sub-arrays 
    // make sure pivot-1 and pivot+1 does not fall outside the array
    quick_sort(A, start_idx, ((pivot-1)<start_idx)?start_idx:pivot-1);
    quick_sort(A, ((pivot+1)>end_idx)?end_idx:pivot+1, end_idx);
    
}


int main()
{
    int count;
    cin >> count;
    
    int *myArray = new int[count];
    
    for (int i=0; i< count; i++)
        cin >> myArray[i];
        
    quick_sort (myArray, 0, count-1);
    
    for (int i=0; i< count; i++)
        cout << myArray[i] << " ";        

}
