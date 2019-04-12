
#ifndef QUICKSORT_H
#define QUICKSORT_H
/**
 * Initial state of quick sort's procedure. Calculates the pivot and split sections.
 * @param int v[] array to sort
 * @param int start first element
 * @param int end last element
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void quickSort(int v[], int start, int end, Data * cmp);

/**
 * Sorts the splitted array
 * @param int v[] array to split
 * @param int start first element of section
 * @param int end last element of section.
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 * @returns a posição do atual pivô.
 */
int arraySplit(int v[], int start, int end, Data * cmp);

/**
 * Initial state of quick sort's procedure with dual pivot. Calculates the pivot and split sections.
 * The dual pivot methdo divides an array in three sections instead of two.
 * @param int v[] array to sort
 * @param int low first element
 * @param int high last element
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void dualPivotQuickSort(int v[], int low, int high, Data * cmp);

/**
 * Sorts and set the left pivot by reference.
 * @param int v[] array to sort.
 * @param int low first element of the section.
 * @param int high last element of the section.
 * @param int *lp reference to the left pivot over array.
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 * @returns a posição do atual pivô
 */ 
int partition(int v[], int low, int high, int *lp, Data * cmp);

#endif /* QUICKSORT_H */

