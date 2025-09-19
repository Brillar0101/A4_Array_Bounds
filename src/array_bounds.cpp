#include "array_bounds.hpp"
#include <algorithm> // std::lower_bound std::upper_bound

// Standard library functions for testing
int std_lower_bound(const int* arr, int n, int target) {
    auto it = std::lower_bound(arr, arr + n, target);
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_upper_bound(const int* arr, int n, int target) {
    auto it = std::upper_bound(arr, arr + n, target);
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_frequency(const int *arr, int n, int target) {
    int lb = std_lower_bound(arr, n, target);
    int ub = std_upper_bound(arr, n, target);
    return ub - lb;
}

// Recursive versions
int lower_bound(const int* arr, int n, int target) {
    return lower_bound_recursive(arr, 0, n, target);
}

int upper_bound(const int* arr, int n, int target) {
    return upper_bound_recursive(arr, 0, n, target);
}

int frequency(const int *arr, int n, int target) {
    return upper_bound(arr, n, target) - lower_bound(arr, n, target);
}

// Recursive helper versions
int lower_bound_recursive(const int* arr, int low, int high, int target) {
    if (low >= high) {
        return low;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] >= target) {
        return lower_bound_recursive(arr, low, mid, target);
    } else {
        return lower_bound_recursive(arr, mid + 1, high, target);
    }
}

int upper_bound_recursive(const int* arr, int low, int high, int target) {
    if (low >= high) {
        return low;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] > target) {
        return upper_bound_recursive(arr, low, mid, target);
    } else {
        return upper_bound_recursive(arr, mid + 1, high, target);
    }
}

// Iterative versions
int lower_bound_iterative(const int* arr, int n, int target) {
    int low = 0;
    int high = n;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

int upper_bound_iterative(const int* arr, int n, int target) {
    int low = 0;
    int high = n;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

int frequency_iterative(const int *arr, int n, int target) {
    return upper_bound_iterative(arr, n, target) - lower_bound_iterative(arr, n, target);
}