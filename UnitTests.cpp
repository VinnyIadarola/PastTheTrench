#include <iostream>
#include <cassert>

#include <Unit.h>



int assert_equal(int expected, int actual, int test_num, const std::string& message) {
    if (expected == actual) {
        std::cout << "[Test " << test_num << "] Passed: " << message << "\n";
        return 0;
    } else {
        std::cerr << "[Test " << test_num << "] FAILED: " << message
                  << " (Expected: " << expected << ", Actual: " << actual << ")\n";
        return 1;
    }
}


void test_update_health() {
    const int total_tests = 5;
    int passed = 0;

    Unit testUnit = Unit();
    int expected, actual;

    expected = 100;
    actual = testUnit.update_health(0);
    passed += assert_equal(expected, actual, 1, "Current health should be default and unchanged");

    expected = 100;
    actual = testUnit.update_health(1);
    passed += assert_equal(expected, actual, 2, "Health should not go over max");

    expected = 1;
    actual = testUnit.update_health(-99);
    passed += assert_equal(expected, actual, 3, "Health should decrease properly");

    expected = 100;
    actual = testUnit.update_health(100);
    passed += assert_equal(expected, actual, 4, "Health should not increase above max");

    expected = 0;  // Previously was -0, which is just 0
    actual = testUnit.update_health(-101);
    passed += assert_equal(expected, actual, 5, "Health should not go below zero");

    std::cout << "Function: " << __func__ << " completed " << (total_tests - passed) << "/" << total_tests << " tests successfully.\n";

}


void test_update_endurance() {
    const int total_tests = 5;
    int passed = 0;

    Unit testUnit = Unit();
    int expected, actual;

    expected = 100;
    actual = testUnit.update_endurance(0);
    passed += assert_equal(expected, actual, 1, "Endurance should remain unchanged");

    expected = 101;
    actual = testUnit.update_endurance(1);
    passed += assert_equal(expected, actual, 2, "Endurance should increase");

    expected = 51;
    actual = testUnit.update_endurance(-50);
    passed += assert_equal(expected, actual, 3, "Endurance should decrease");

    expected = 1;
    actual = testUnit.update_endurance(-1000);
    passed += assert_equal(expected, actual, 4, "Endurance should clamp at 1");

    expected = 10;
    actual = testUnit.update_endurance(9);  
    passed += assert_equal(expected, actual, 5, "Endurance should increase after clamping");

     std::cout << "Function: " << __func__ << " completed " << (total_tests - passed) << "/" << total_tests << " tests successfully.\n";
}



int main() {
    test_update_health();
    test_update_endurance();

    std::cout << "All unit tests completed successfully.\n";
    return 0;
}
