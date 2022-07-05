//#include <iostream>
#include <iterator> // for std::size
#include <utility> //for std::swap

template <typename T>
void selectionSort(T arr[], int size, bool desc = false) {
    //comparing last element is redundant
    for(int i{ 0 }; i < size - 1; ++i) {
    /*if a smaller/larger value is found, set ind to the index of that
    value and swap it with i when you're done*/
    int ind{ i };
    for(int j{ i + 1 }; j < size; ++j) {
        if( (!desc && arr[j] < arr[ind]) || (desc && arr[j] > arr[ind])) {
            ind = j;
        }
    }
        std::swap(arr[i], arr[ind]);
    }
}

template <typename T>
void bubbleSort(T arr[], int size, bool desc = false) {
    /*A) Compare array element 0 with array element 1. If element 0 is larger, 
    swap it with element 1.
    B) Now do the same for elements 1 and 2, and every subsequent pair of 
    elements until you hit the end of the array. At this point, the last 
    element in the array will be sorted.
    C) Repeat the first two steps again until the array is sorted.*/
    for(int i{ 0 }; i < size - 1; ++i) {
        bool sorted { true };
        /*no need to recheck sorted elements and if we pass without swaps
        then the array is sorted*/
        for(int j{ 1 }; j < size - i; ++j) {
            if( (!desc && arr[j] < arr[j - 1]) || (desc && arr[j] > arr[j - 1]) ) {
                std::swap(arr[j], arr[j - 1]);
                sorted = false;
            }
        }
        if(sorted) {
            break;
        }
    }
}

template <typename T>
int binarySearch(const T* array, int target, int min, int max) {
    // You can use std::binarysearch in production code
    while(min <= max) {
        // can't do (min + max) / 2 because it may lead to overflow
        //for c++ or above, you can use std::midpoint() from <numerical> header
        int mid { min + (max - min) / 2}; 
         
        // if current val is less than target, discard the lower half
        if(array[mid] < target) {
            min = mid + 1;
        }
        // if current val is more than target, discard the higher half
        else if(array[mid] > target) {
            max = mid - 1;
        }
        // val is equal to target
        else {
            return mid;
        }
    }

    return -1;
    /* recursive approach:
    if(min > max)
        return -1;

    int mid{ min + (max - min) / 2};
    if(array[mid] < target) {
        return binarySearch(array, target, mid + 1, max);
    }
    else if(array[mid] > target) {
        return binarySearch(array, target, min, mid - 1);
    }
    else {
        return mid;
    }*/
}