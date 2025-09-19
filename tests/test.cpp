#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "array_bounds.hpp"

TEST_CASE("lower_bound tests", "[lower_bounds_both_methods]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(lower_bound_iterative(arr, n, 5) == 1);
    REQUIRE(lower_bound(arr, n, 5) == 1);
    REQUIRE(lower_bound_iterative(arr, n, 3) == 1);
    REQUIRE(lower_bound(arr, n, 11) == 5);
}

TEST_CASE("upper_bound tests","[upper_bound_both_methods]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(upper_bound_iterative(arr, n, 5) == 4);
    REQUIRE(upper_bound(arr, n, 5) == 4);
    REQUIRE(upper_bound_iterative(arr, n, 2) == 1);
    REQUIRE(upper_bound(arr, n, 10) == 5);
}

TEST_CASE("frequency tests",  "[frequency]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(frequency(arr, n, 5) == 3);
    REQUIRE(frequency_iterative(arr, n, 5) == 3);
    REQUIRE(frequency(arr, n, 2) == 1);
    REQUIRE(frequency_iterative(arr, n, 7) == 0);
}

TEST_CASE("compare with std library", "[std_library]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(lower_bound_iterative(arr, n, 5) == std_lower_bound(arr, n, 5));
    REQUIRE(upper_bound_iterative(arr, n, 5) == std_upper_bound(arr, n, 5));
    REQUIRE(frequency(arr, n, 5) == std_frequency(arr, n, 5));
}

TEST_CASE("edge cases", "[edge_case]") {
    int single[] = {7};
    int n = 1;
    
    REQUIRE(lower_bound_iterative(single, n, 7) == 0);
    REQUIRE(upper_bound_iterative(single, n, 7) == 1);
    REQUIRE(frequency(single, n, 7) == 1);
    REQUIRE(frequency_iterative(single, n, 5) == 0);
}