//
// Created by Lenovo on 03.02.2020.
//

#ifndef RPM_LABS_SENTINELSEARCH_H
#define RPM_LABS_SENTINELSEARCH_H
#include <iostream>

/**
 * Search for an element in an array
 * @param toSearch
 * @param array Target array
 * @param size Array size
 * @return Index of the element, -1 if not found
 */
template <typename T>
int sentinelSearch(T toSearch, T* array, const int size){
  int lastIndex = size-1;
  int last=array[lastIndex];
  array[lastIndex]=toSearch;
  int i = 0;
  while (array[i]!=toSearch)
    i++;
  array[lastIndex] = last;

  if ( (i<lastIndex) or (toSearch==last) ) {
    return i;
  }
  else{
    return -1;
  }
}


#endif //RPM_LABS_SENTINELSEARCH_H
