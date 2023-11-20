#include <iostream>
using namespace std;

// sort 
  int partition(long long array[], int start, int end){
    int i, j;
    long long pivot;
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
  void quickSort(long long array[], int start, int end){
    if(start < end){
      long long pivot;
      pivot = partition(array, start, end);
      quickSort(array, start, pivot - 1);
      quickSort(array, pivot + 1, end);
    }
  }

int main(){

  int num_bars, num_coupons;
  long long total_sum = 0;

  // chocolate bars
  cin >> num_bars;
  long long bars_prices[num_bars];

  for(int i = 0; i < num_bars; i++){
    cin >> bars_prices[i];
    total_sum += bars_prices[i];
  }

  // sort bars_prices
  quickSort(bars_prices, 0, num_bars-1);
  
  // cupons
  cin >> num_coupons;
  int coupons[num_coupons];
  
  for(int i = 0; i < num_coupons; i++){
    int y;
    long long sum = 0;
    int ignore;
    cin >> y;
    ignore = num_bars - y;
    sum = total_sum - bars_prices[ignore];
    cout << sum << "\n";
  }


  return 0;
}