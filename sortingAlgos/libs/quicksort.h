
#ifndef QUICKSORT_H
#define QUICKSORT_H
/**
 * Initial state of quick sort's procedure. Calculates the pivot and split sections.
 * @param int v[] array to sort
 * @param int start first element
 * @param int end last element
 */ 
void quickSort(int v[], int start, int end);

/**
 * Sorts the splitted array
 * @param int v[] array to split
 * @param int start first element of section
 * @param int end last element of section.
 * @returns int pos the current pivot position
 */
int arraySplit(int v[], int start, int end);

/**
 * Initial state of quick sort's procedure with dual pivot. Calculates the pivot and split sections.
 * The dual pivot methdo divides an array in three sections instead of two.
 * @param int v[] array to sort
 * @param int low first element
 * @param int high last element
 */ 
void dualPivotQuickSort(int v[], int low, int high);

/**
 * Sorts and set the left pivot by reference.
 * @param int v[] array to sort.
 * @param int low first element of the section.
 * @param int high last element of the section.
 * @param int *lp reference to the left pivot over array.
 * @returns int pos the current pivot position.
 */ 
int partition(int v[], int low, int high, int *lp);

#endif /* QUICKSORT_H */

