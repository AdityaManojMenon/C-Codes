#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "sort.h"

void display_vector(const std::vector<int>& vec) {
  std::copy(vec.begin(), vec.end(),
            std::ostream_iterator<double>(std::cout, " "));
  std::cout << std::endl;
}

void swap(std::vector<int>& vec, int i, int j) {
  if (i == j) {
    return;
  }
  int temp = vec[i];
  vec[i] = vec[j];
  vec[j] = temp;
  display_vector(vec);
}

// From Pseudocode on https://en.wikipedia.org/wiki/Bubble_sort
void bubble_sort(std::vector<int> A) {
  display_vector(A);
  int n = static_cast<int>(A.size());
  while (true) {
    bool swapped = false;
    for (int i{1}; i <= n - 1; ++i) {
      if (A.at(i - 1) > A.at(i)) {
        swap(A, i - 1, i);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}


// From Pseudocode on https://en.wikipedia.org/wiki/Quicksort
int partition(std::vector<int> & A, int lo, int hi) {
  int pivot{A.at(hi)};
  int i{lo};
  for (int j{lo}; j <= hi - 1; ++j) {
    if (A.at(j) <= pivot) {
      swap(A, i, j);
      ++i;
    }
  }
  swap(A, i, hi);
  return i;
}

void quicksort_sort(std::vector<int> & A, int lo, int hi) {
  if (lo >= hi || lo < 0) {
    return;
  }
  int p = partition(A, lo, hi);
  quicksort_sort(A, lo, p - 1);
  quicksort_sort(A, p + 1, hi);
}

void quicksort_sort(std::vector<int> A) {
  display_vector(A);
  quicksort_sort(A, 0, A.size() - 1);
  
}



// From Pseudocode on https://en.wikipedia.org/wiki/Insertion_sort
void insertion_sort(std::vector<int> A) {
  display_vector(A);
  int i{1};
  while (i < static_cast<int>(A.size())) {
    int j{i};
    while (j > 0 && (A.at(j - 1) > A.at(j))) {
      swap(A, j, j - 1);
      --j;
    }
    ++i;
  }
}