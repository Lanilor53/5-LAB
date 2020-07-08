//
// Created by Lenovo on 03.02.2020.
//

#ifndef RPM_LABS_BINARYSEARCH_H
#define RPM_LABS_BINARYSEARCH_H
#include <iostream>

/**
 * Search for an element in an array
 * @param toSearch
 * @param array Target array
 * @param size Array size
 * @return Index of the element, -1 if not found
 */
template <typename T>
int binarySearch(T toSearch, T* array, const int size){
  int start = 0;
  int end = size-1;
  int center;
  while(true){
    center = start + (int)(end-start)/2;
    if(array[center] == toSearch)
      break;
    if(array[center] > toSearch){
      start = center+1;
    }else{
      end = center-1;
    }
    if(end<start){
      return -1;
    }
  }
  return center;
}


#endif //RPM_LABS_BINARYSEARCH_H
