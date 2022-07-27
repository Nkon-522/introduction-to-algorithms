#include <iostream>
#include <functional> // less
#include <vector>
using namespace std;

template<template<typename...> typename Cnt, typename T>
void print(Cnt<T> cnt){
  for(auto& x:cnt){
    cout<<x<<" ";
  }
  cout<<endl;
}

template<typename cmp = greater<>, template<typename...> typename Cnt, typename T>
void insertion_sort(Cnt<T>& cnt){
  // container size
  int n = static_cast<int>(distance(begin(cnt), end(cnt)));
  // array has three parts 
  // left -> sorted array
  // idx -> current key
  // right -> original array
  for(int i=1; i < n;i++){
    auto key = cnt[i];
    // Insert key into the sorted subarray cnt[1:i-1]
    int j = i-1;
    // Move all elements to the right before i until j is at start or cnt[j] passes condition 
    cmp comparator;
    while(j >= 0 && comparator(cnt[j], key)){
      cnt[j+1] = cnt[j];
      j=j-1;
    }
    // Insert key to the right of the element
    cnt[j+1] = key;
  }
}

int main(){
  vector<int> a = {5,2,4,6,1,3};
  print(a);
  insertion_sort(a);
  print(a);
  insertion_sort<less<>>(a);
  print(a);
  return 0;
}
