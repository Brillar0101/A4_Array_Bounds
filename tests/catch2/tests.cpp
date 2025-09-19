#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array_bounds.hpp"

TEST_CASE("Lower bound iterative tests", "[lower_bound][iterative]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(lower_bound_iterative(arr, n, -1) == 0);  // Before all elements
    REQUIRE(lower_bound_iterative(arr, n, 0) == 0);   // Before all elements
    REQUIRE(lower_bound_iterative(arr, n, 2) == 0);   // First element
    REQUIRE(lower_bound_iterative(arr, n, 3) == 1);   // Between 2 and 5
    REQUIRE(lower_bound_iterative(arr, n, 5) == 1);   // First occurrence of 5
    REQUIRE(lower_bound_iterative(arr, n, 6) == 4);   // Between 5 and 10
    REQUIRE(lower_bound_iterative(arr, n, 10) == 4);  // Last element
    REQUIRE(lower_bound_iterative(arr, n, 11) == 5);  // After all elements
}

TEST_CASE("Upper bound iterative tests", "[upper_bound][iterative]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(upper_bound_iterative(arr, n, -1) == 0);  // Before all elements
    REQUIRE(upper_bound_iterative(arr, n, 0) == 0);   // Before all elements
    REQUIRE(upper_bound_iterative(arr, n, 2) == 1);   // After first element
    REQUIRE(upper_bound_iterative(arr, n, 3) == 1);   // Between 2 and 5
    REQUIRE(upper_bound_iterative(arr, n, 5) == 4);   // After last occurrence of 5
    REQUIRE(upper_bound_iterative(arr, n, 6) == 4);   // Between 5 and 10
    REQUIRE(upper_bound_iterative(arr, n, 10) == 5);  // After last element
    REQUIRE(upper_bound_iterative(arr, n, 11) == 5);  // After all elements
}

TEST_CASE("Lower bound recursive tests", "[lower_bound][recursive]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(lower_bound(arr, n, -1) == 0);  // Before all elements
    REQUIRE(lower_bound(arr, n, 0) == 0);   // Before all elements
    REQUIRE(lower_bound(arr, n, 2) == 0);   // First element
    REQUIRE(lower_bound(arr, n, 3) == 1);   // Between 2 and 5
    REQUIRE(lower_bound(arr, n, 5) == 1);   // First occurrence of 5
    REQUIRE(lower_bound(arr, n, 6) == 4);   // Between 5 and 10
    REQUIRE(lower_bound(arr, n, 10) == 4);  // Last element
    REQUIRE(lower_bound(arr, n, 11) == 5);  // After all elements
}

TEST_CASE("Upper bound recursive tests", "[upper_bound][recursive]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    REQUIRE(upper_bound(arr, n, -1) == 0);  // Before all elements
    REQUIRE(upper_bound(arr, n, 0) == 0);   // Before all elements
    REQUIRE(upper_bound(arr, n, 2) == 1);   // After first element
    REQUIRE(upper_bound(arr, n, 3) == 1);   // Between 2 and 5
    REQUIRE(upper_bound(arr, n, 5) == 4);   // After last occurrence of 5
    REQUIRE(upper_bound(arr, n, 6) == 4);   // Between 5 and 10
    REQUIRE(upper_bound(arr, n, 10) == 5);  // After last element
    REQUIRE(upper_bound(arr, n, 11) == 5);  // After all elements
}

TEST_CASE("Frequency tests", "[frequency]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    SECTION("Recursive frequency") {
        REQUIRE(frequency(arr, n, -1) == 0);  // Not present
        REQUIRE(frequency(arr, n, 0) == 0);   // Not present
        REQUIRE(frequency(arr, n, 2) == 1);   // Single occurrence
        REQUIRE(frequency(arr, n, 3) == 0);   // Not present
        REQUIRE(frequency(arr, n, 5) == 3);   // Multiple occurrences
        REQUIRE(frequency(arr, n, 6) == 0);   // Not present
        REQUIRE(frequency(arr, n, 10) == 1);  // Single occurrence
        REQUIRE(frequency(arr, n, 11) == 0);  // Not present
    }
    
    SECTION("Iterative frequency") {
        REQUIRE(frequency_iterative(arr, n, -1) == 0);  // Not present
        REQUIRE(frequency_iterative(arr, n, 0) == 0);   // Not present
        REQUIRE(frequency_iterative(arr, n, 2) == 1);   // Single occurrence
        REQUIRE(frequency_iterative(arr, n, 3) == 0);   // Not present
        REQUIRE(frequency_iterative(arr, n, 5) == 3);   // Multiple occurrences
        REQUIRE(frequency_iterative(arr, n, 6) == 0);   // Not present
        REQUIRE(frequency_iterative(arr, n, 10) == 1);  // Single occurrence
        REQUIRE(frequency_iterative(arr, n, 11) == 0);  // Not present
    }
}

TEST_CASE("Comparison with standard library", "[comparison]") {
    int arr[] = {2, 5, 5, 5, 10};
    int n = 5;
    
    for (int target : {-1, 0, 2, 3, 5, 6, 10, 11}) {
        SECTION("Target: " + std::to_string(target)) {
            // Test that custom implementations match standard library
            REQUIRE(lower_bound_iterative(arr, n, target) == std_lower_bound(arr, n, target));
            REQUIRE(upper_bound_iterative(arr, n, target) == std_upper_bound(arr, n, target));
            REQUIRE(lower_bound(arr, n, target) == std_lower_bound(arr, n, target));
            REQUIRE(upper_bound(arr, n, target) == std_upper_bound(arr, n, target));
            REQUIRE(frequency(arr, n, target) == std_frequency(arr, n, target));
            REQUIRE(frequency_iterative(arr, n, target) == std_frequency(arr, n, target));
        }
    }
}

TEST_CASE("Edge cases", "[edge_cases]") {
    SECTION("Single element array") {
        int arr[] = {5};
        int n = 1;
        
        REQUIRE(lower_bound_iterative(arr, n, 3) == 0);
        REQUIRE(lower_bound_iterative(arr, n, 5) == 0);
        REQUIRE(lower_bound_iterative(arr, n, 7) == 1);
        
        REQUIRE(upper_bound_iterative(arr, n, 3) == 0);
        REQUIRE(upper_bound_iterative(arr, n, 5) == 1);
        REQUIRE(upper_bound_iterative(arr, n, 7) == 1);
        
        REQUIRE(frequency_iterative(arr, n, 5) == 1);
        REQUIRE(frequency_iterative(arr, n, 3) == 0);
    }
    
    SECTION("All same elements") {
        int arr[] = {5, 5, 5, 5};
        int n = 4;
        
        REQUIRE(lower_bound_iterative(arr, n, 5) == 0);
        REQUIRE(upper_bound_iterative(arr, n, 5) == 4);
        REQUIRE(frequency_iterative(arr, n, 5) == 4);
        
        REQUIRE(lower_bound(arr, n, 5) == 0);
        REQUIRE(upper_bound(arr, n, 5) == 4);
        REQUIRE(frequency(arr, n, 5) == 4);
    }
    
    SECTION("Strictly increasing array") {
        int arr[] = {1, 3, 5, 7, 9};
        int n = 5;
        
        REQUIRE(frequency_iterative(arr, n, 5) == 1);
        REQUIRE(frequency_iterative(arr, n, 4) == 0);
        REQUIRE(frequency(arr, n, 5) == 1);
        REQUIRE(frequency(arr, n, 4) == 0);
    }
}

SCENARIO("Binary search behavior", "[BDD]") {
    GIVEN("A sorted array with duplicates") {
        int arr[] = {2, 5, 5, 5, 10};
        int n = 5;
        
        WHEN("searching for an element that exists") {
            int target = 5;
            
            THEN("lower bound points to first occurrence") {
                REQUIRE(lower_bound_iterative(arr, n, target) == 1);
                REQUIRE(lower_bound(arr, n, target) == 1);
            }
            
            THEN("upper bound points after last occurrence") {
                REQUIRE(upper_bound_iterative(arr, n, target) == 4);
                REQUIRE(upper_bound(arr, n, target) == 4);
            }
            
            THEN("frequency equals number of occurrences") {
                REQUIRE(frequency_iterative(arr, n, target) == 3);
                REQUIRE(frequency(arr, n, target) == 3);
            }
        }
        
        WHEN("searching for an element that doesn't exist") {
            int target = 3;
            
            THEN("lower and upper bounds are equal") {
                REQUIRE(lower_bound_iterative(arr, n, target) == upper_bound_iterative(arr, n, target));
                REQUIRE(lower_bound(arr, n, target) == upper_bound(arr, n, target));
            }
            
            THEN("frequency is zero") {
                REQUIRE(frequency_iterative(arr, n, target) == 0);
                REQUIRE(frequency(arr, n, target) == 0);
            }
        }
    }
}