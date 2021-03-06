/** File at3.c
 * @author Tushar Narayan
 *
 * Program for generating an array of random integers,
 * printing them, then sorting the array and printing
 * it again.
 */

/**
 * tnarayan@wpi.edu
 */

#include <stdio.h>
#include "print_arrays.h"
#include "array_functions.h"

/** Generates an array of random integers and prints it.
 * Then sorts the array and prints it again.
 * @return 0 Indicates successful program completion.
 */
/* function main begins program execution */
int main( void )
{
  int a[RANDOM_ARRAY_SIZE]; /* array to store integers */
  
  /* instructions */
  printf( "\nWelcome \n" );
  printf( "\nI will generate and print an array of random integers." );
  printf( "\nThe random numbers will be between 0 and %d.", RANDOM_MAX_NUM );
  printf( " Then I will sort them and print the sorted array.\n" );
  
  // calling function to generate the random integers array  
  generate_random_array(a);

  printf( "\nGenerating random numbers now...\n" );
  // call function to print the array
  print_int_array(a, RANDOM_ARRAY_SIZE);
  
  // call function to sort the array
  bubble_sort(a, RANDOM_ARRAY_SIZE);
  
  printf( "\nSorted form of the array is:\n" );
  // call function to print the sorted array
  print_int_array(a, RANDOM_ARRAY_SIZE);
    
  return 0; /* indicate program ended successfully */
} //end of main
