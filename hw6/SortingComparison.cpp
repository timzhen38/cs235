//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************


#include "SortingComparison.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]){}



/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/


int SortingComparison::comparisons = 0; // defining the static data member
/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to)
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (a[i] < a[min_pos]) 
        {
            min_pos = i; 
        }
        comparisons++;
    }
    return min_pos;
}


/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::selectionSort(int a[], size_t size)
{
    comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        // Find the position of the minimum
        int min_pos = minPosition(a, i, static_cast<int>(size - 1));
        // Swap the next element and the minimum
        std::swap(a[i], a[min_pos]);
    }


    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}




/*************** INSERTION SORT **************************/


/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
 */
int SortingComparison::insertionSort(int a[], size_t size)
{
    comparisons = 0;
    for (int i = 1; i < size; i++)
    {
        int next = a[i];
        // Move all larger elements up
        int j = i;
        //counts comparisons where a[j-1] is less than the next number
        if (a[j-1] <= next)
        {
            comparisons++;
        }
        while (j > 0 && a[j - 1] > next)
        {
            comparisons++;
            a[j] = a[j - 1];
            j--;
        }
        // Insert the element
        a[j] = next;
    }

    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to, int& comparisonsMerge)
{
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
        {
            temp_array[j] = a[i1];
            i1++;
            comparisonsMerge++;
        }
        else
        {
           temp_array[j] = a[i2];
            i2++;
            comparisonsMerge++;
        }
        j++;
    }


    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid)
    {
        comparisonsMerge++;
        temp_array[j] = a[i1];
        i1++;
        j++;
    }
    // Copy any remaining entries of the second half
    while (i2 <= to)
    {
        comparisonsMerge++;
        temp_array[j] = a[i2];
        i2++;
        j++;
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++)
    {
        a[from + j] = temp_array[j];
    }

    delete[] temp_array;
}

/**
 @post Sorts the elements in a range of a array.
 @param a the array with the elements to sort
 @param from the first position in the range to sort
 @param to the last position in the range to sort (included)
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::mergeSort(int a[], int from, int to)
{
    int comparisonsMerge = 0;
    if (from == to) { return 0; }
    int mid = (from + to) / 2;
    // Recursively sort the first and the second half
    comparisonsMerge+=mergeSort(a, from, mid);
    comparisonsMerge+=mergeSort(a, mid + 1, to);
    merge(a, from, mid, to,comparisonsMerge);

    comparisons = 0; // have to reset comparisons to 0 for quicksort
    return comparisonsMerge;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* QUICK SORT + HELPER**************************/

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to)
{
   int pivot = a[from];
   int i = from - 1; //index of data item being compared from left
   int j = to + 1;   //index of data item being compared from right
   while (i < j)    // as long as i and j did not cross (meet)
   {
      i++;
      while (a[i] < pivot)//increment i until a[i] >= pivot
      {
          i++;
          comparisons++; //comparing elements in a[i] < pivot
      }

      j--;
      while (a[j] > pivot) //decrement j until a[j] <= pivot
      {
          j--;
          comparisons++; //comparing elements in a[j] > pivot
      }

      if (i < j)
          std::swap(a[i], a[j]);
   }
   return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to)
{
    if (from >= to){return 0;}

    int p = partition(a, from, to);
    quickSort(a, from, p);
    quickSort(a, p + 1, to);


    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}





/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/


  //*************  IMPLEMENT runComparison HERE!!!! ************//
/*
    @post Sorts a copy of values_ in ascending order with each available sorting functions
    and prints the number of comparisons made by each sorting algorithm
    @param array_type data_distribution of values_ in {RANDOM, INCREASING, DECREASING}
*/
 void SortingComparison::runComparison(data_distribution array_type)
 {  
    //4 copies of values_ for the 4 sorting methods
    int valuesSelect[SIZE];
    int valuesInsert[SIZE];
    int valuesMerge[SIZE];
    int valuesQuick[SIZE];

    srand(static_cast<unsigned>(time(0))); 
    //insert values into the array based on array_type
    if (array_type == RANDOM)
    {
        for (int i = 0; i < SIZE; i++)
        {
            values_[i] = rand() % SIZE;
        }
    }
    if (array_type == INCREASING)
    {
        for (int i = 0; i < SIZE; i++)
        {
            values_[i] = i;
        }
    }
    if (array_type == DECREASING)
    {
        int pos = 0; //for inserting numbers from the beginning of the array
        for (int i = SIZE-1; i > -1; i--)
        {
            values_[pos] = i;
            pos++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        valuesSelect[j] = values_[j];
        valuesInsert[j] = values_[j];
        valuesMerge[j] = values_[j];
        valuesQuick[j] = values_[j];
    }

    cout << "Selection sort comparisons: " << selectionSort(valuesSelect,SIZE) << endl << endl;
    cout << "Insertion sort comparisons: " << insertionSort(valuesInsert,SIZE) << endl << endl;
    cout << "Merge sort comparisons: " << mergeSort(valuesMerge,0,SIZE-1) << endl << endl;
    cout << "Quick sort comparisons: " << quickSort(valuesQuick,0,SIZE-1) << endl << endl;


 }
