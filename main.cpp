//
// Created by Lenovo on 03.02.2020.
//
#include <iostream>
#include <random>
#include <time.h>
#include <array>
#include "binarysearch.h"
#include "sentinelsearch.h"
#include "heapsort.h"
#include <chrono>

/**
 * Prints the array in format [1,2,...n]
 * @tparam T
 * @param array
 */
template<typename T>
void printArr(T* array, int size){
  std::cout << "[";
  for(int i = 0; i < size; i++){
    std::cout << array[i] << ", ";
  }
  std::cout << "\b\b]\n";
}



int main(){
  //Setup random
  std::mt19937 mt(time(nullptr));
  const int RANDOM_MIN = 0;
  const int RANDOM_MAX = 5999999;
  std::uniform_int_distribution<int> uid(RANDOM_MIN,RANDOM_MAX);
  // Generating the large target array
  const int ARRSIZE = 300000;
  int* array = new int[ARRSIZE];
  for(int i = 0; i < ARRSIZE; i++){
    array[i] = uid(mt);
  }

  // Generating the 40-element search array
  const int SEARCHARRSIZE = 40;
  int* searchArray = new int[SEARCHARRSIZE];
  for(int i = 0; i < SEARCHARRSIZE; i++){
    searchArray[i] = uid(mt);
  }

  printArr<int>(searchArray, SEARCHARRSIZE);

  // We will first search in unsorted array
  int* resultArray = new int[SEARCHARRSIZE];
  auto begin = std::chrono::steady_clock::now();
  for(int i=0;i<SEARCHARRSIZE;i++){
    resultArray[i] = sentinelSearch<int>(searchArray[i], array, ARRSIZE);
  }
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
  std::cout << "Sentinel search finished in " << elapsed.count() << " milliseconds\n";
  std::cout << "Results:\n";
  printArr<int>(resultArray,SEARCHARRSIZE);
  // Now we will search in sorted array
  resultArray = new int[SEARCHARRSIZE];
  begin = std::chrono::steady_clock::now();
  array = heapSort<int>(array, ARRSIZE);
  now = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
  std::cout << "Array sorted in " << elapsed.count() << " milliseconds\n";
  begin = std::chrono::steady_clock::now();
  for(int i=0;i<SEARCHARRSIZE;i++){
    resultArray[i] = binarySearch<int>(searchArray[i], array, ARRSIZE);
  }
  now = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
  std::cout << "Binary search finished in " << elapsed.count() << " milliseconds\n";
  std::cout << "Results:\n";
  printArr<int>(resultArray,SEARCHARRSIZE);

  return 0;
}
