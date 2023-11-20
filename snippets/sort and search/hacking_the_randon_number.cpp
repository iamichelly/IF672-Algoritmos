#include <iostream>
using namespace std;

// sort 
  int partition(int array[], int start, int end){
    int i, j;
    int pivot;
    pivot = array[start];
    i = start;
    j = end + 1;
    do{
      do
      {
        i = i + 1;
      }while(array[i] < pivot && i < j);

      do {
        j = j - 1;
      }while(array[j] > pivot);

      swap(array[i], array[j]);
    }while(i < j);

    swap(array[i], array[j]);
    swap(array[start], array[j]);
    
    // return pivot position
    return j;
  }
  void quickSort(int array[], int start, int end){
    if(start < end){
      int pivot;
      pivot = partition(array, start, end);
      quickSort(array, start, pivot - 1);
      quickSort(array, pivot + 1, end);
    }
  }

  int binarySearch(int array[], int l, int r, int k){
    while(l <= r){
      int m;
      m = (l+r)/2;
      if(k == array[m]){    
        return m;
      }else if(k < array[m]){
        r = m-1;
      }else{
        l = m+1;
      }
    }

    return -1;
  }

int main(){

  int n, k, ans = 0;
  cin >> n >> k;
  int numbers[n];
  // read numbers
  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }
  // sort numbers
  quickSort(numbers, 0, n-1);
  int value = 0;
  for(int i = 0; i < n; i++){
    int j, value;
    j = numbers[i] + k;
    value = binarySearch(numbers, 0, n-1, j);
    if(value != -1){
      ans++;
    }
  }
 
  cout << ans;

  return 0;
}