#include <stdcountof.h>
#include <stddef.h>
#include <stdio.h>

int TEST_ARR[] = {5, 3, -2, 4, 4, 9};

void swap(int *a, int *b) {
  // YOUR CODE HERE
}

void bubble_sort(int *arr, size_t size, bool (*is_in_order)(int a, int b)) {
  // YOUR CODE HERE
}

// YOUR CODE HERE

void print_arr(int *arr, size_t size) {
  for (size_t i = 0; i < size; ++i)
    printf("%d ", arr[i]);
  puts("");
}

int main() {
  puts("Input:");
  print_arr(TEST_ARR, countof(TEST_ARR));
  puts("");

  puts("Ascending");
  bubble_sort(TEST_ARR, countof(TEST_ARR), is_in_ascending_order);
  print_arr(TEST_ARR, countof(TEST_ARR));
  puts("");

  puts("Descending");
  bubble_sort(TEST_ARR, countof(TEST_ARR), is_in_descending_order);
  print_arr(TEST_ARR, countof(TEST_ARR));
}