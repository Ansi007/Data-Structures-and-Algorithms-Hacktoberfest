#include<stdio.h>
#include<stdlib.h>
int arr[3];
int S[3];
int C[3];
void displayArr(int arr[], int cap)
{
    printf("\n");
    for(int i = 0;i < cap; +i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int sum_arr(int A[],int low, int high)
{
  int sum = 0;
  for(int i = low; i <= high; i++)
  {
    sum = sum + A[i];
  }
  return sum;
}

void find_max_sum_subArray_quadratic(int A[], int low, int high)
{
  int maxSum = -1000;
  int startIndex = low;
  int endIndex = low;
  int S[3];
  for(int i = low;i <= high; i++)
  {
    int tempSum = 0;
    for(int j = i; j <= high; j++)
    {
      tempSum = tempSum + A[j];
      if(tempSum > maxSum)
      {
        maxSum = tempSum;
        startIndex = i;
        endIndex = j;
      }
    }
    S[0] = maxSum;
    S[1] = startIndex;
    S[2] = endIndex;
  }
  displayArr(S,3);
}

void find_max_sum_subArray_cubic(int A[], int low, int high)
{
  int maxSum = -1000;
  int startIndex = low;
  int endIndex = low;
  int S[3];
  for(int i = low;i <= high; i++)
  {
    for(int j = i; j <= high; j++)
    {
      int tempSum = sum_arr(A,i,j);
      if(tempSum > maxSum)
      {
        maxSum = tempSum;
        startIndex = i;
        endIndex = j;
      }
    }
    S[0] = maxSum;
    S[1] = startIndex;
    S[2] = endIndex;
  }
  displayArr(S,3);
}

int *cross_sub_array(int A[], int low, int mid, int high)
{
  int left = -1000;
  int sum = 0;
  int max_left;
  for(int i = mid; i >= low; i--)
  {
    sum = sum + A[i];
    if(sum > left)
    {
        left = sum;
        max_left = i;
    }
  }
  int right = -1000;
  sum = 0;
  int max_right;
  for(int j = mid +1; j <= high; j++)
  {
    sum = sum + A[j];
    if(sum > right)
    {
      right = sum;
      max_right = j;
    }
  }
  C[0] =  max_left;
  C[1] = max_right;
  C[2] = left + right;
  return C;
}

int *find_max_sum_subArray_merge(int A[], int low, int high)
{
  if(high == low)
  {
    S[0] = A[low];
    S[1] = low;
    S[2] = high;
    return S;
  }
  else
  {
    int mid = (low + high)/2;
    
    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;
    
    left_low = *find_max_sum_subArray_merge(A,low,mid);
    left_high = *(find_max_sum_subArray_merge(A,low,mid)+1);
    left_sum = *(find_max_sum_subArray_merge(A,low,mid)+2);

    right_low = *find_max_sum_subArray_merge(A,mid+1,high);
    right_high = *(find_max_sum_subArray_merge(A,mid+1,high)+1);
    right_sum = *(find_max_sum_subArray_merge(A,mid+1,high)+2);

    cross_low = *(cross_sub_array(A,low, mid, high));
    cross_high = *(cross_sub_array(A,low, mid, high)+1);
    cross_sum = *(cross_sub_array(A,low, mid, high)+2);

    if(left_sum >= right_sum && left_sum >= cross_sum)
    {
      arr[0] = left_low;
      arr[0] = left_high;
      return arr;  
    }
    else if(right_sum >= left_sum && right_sum >= cross_sum)
    {
      arr[0] = right_low;
      arr[1] = right_high;
      return arr;
    }
    else if(cross_sum >= right_sum && cross_sum >= left_sum)
    {
      arr[0] = cross_low;
      arr[1] = cross_high;
      return arr;
    }
  }
}


int main()
{
  int arr[7] = {3, 2, 4, 8, 5, 9, 6};
  int *m = find_max_sum_subArray_merge(arr, 0, 6);
  int ptr = *m;
  int ptr2 = *(m+1);
  int sum = 0;
  for(int i = ptr1; i <= ptr2; i++)
  {
    sum = sum + arr[i];
  }
  printf("Given array is: ");
  displayArr(arr,7);
  printf("\n The maximum sum sub array of this given array by linear logarithmic O(nlogn) time: \n %d\n ", sum);
  printf("\n by cubic O(n^3) time: ");
  find_max_sum_subArray_cubic(arr,0,6);
  printf("\n by quadratic O(n^2) time: ");
  find_max_sum_subArray_quadratic(arr, 0, 6);
  return 0;
}
