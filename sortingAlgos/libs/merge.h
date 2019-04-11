#ifndef MERGE_H
#define MERGE_H

/**
 * Initial state for merge sort method. 
 * @param int v[] is the array to sort.
 * @param int left is the first array position.
 * @param int right is the last element
 */ 
void mergeSort(int v[], int left, int right);

/**
 * Sorts and merges the sectioned array by @method mergeSort.
 * @param int v[] is the original array.
 * @param int left is the first element for the section.
 * @param int mid is the middle element for the section.
 * @param int right is the last element for the section.
 */ 
void merge(int v[], int left, int mid, int right);


#endif /* MERGE_H */

