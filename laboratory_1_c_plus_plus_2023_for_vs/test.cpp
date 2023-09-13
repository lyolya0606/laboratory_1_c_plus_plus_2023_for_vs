//
// Created by lyolya on 12.09.2023.
//
#include <iostream>
#include <string>
#include "substring_search.h"

using namespace std;


bool test_1() {
  string text = "hello world hehehe";
  string substring = "he";

  int correct_count = 4;
  int count = search_for_all_substring(text, substring).size();

  if (count == correct_count) {
    return true;
  } else {
    cout << "Test 1 failed!" << endl;
    cout << "Correct count of substrings: " << correct_count << endl;
    cout << "The resulting count of substrings: " << count << endl;
    return false;
  }
}

bool test_2() {
  string text = "hello world hehehe";
  string substring = "z";

  int correct_count = 0;
  int count = search_for_all_substring(text, substring).size();

  if (count == correct_count) {
    return true;
  } else {
    cout << "Test 2 failed!" << endl;
    cout << "Correct count of substrings: " << correct_count << endl;
    cout << "The resulting count of substrings: " << count << endl;
    return false;
  }
}

bool test_3() {
  string text = "really hard tests";
  string substring = "e";

  int correct_count = 2;
  int count = search_for_all_substring(text, substring).size();

  if (count == correct_count) {
    return true;
  } else {
    cout << "Test 3 failed!" << endl;
    cout << "Correct count of substrings: " << correct_count << endl;
    cout << "The resulting count of substrings: " << count << endl;
    return false;
  }
}

bool test_4() {
  string text = "hello hello hell";
  string substring = "hell";

  int correct_count = 3;
  int count = search_for_all_substring(text, substring).size();

  if (count == correct_count) {
    return true;
  } else {
    cout << "Test 4 failed!" << endl;
    cout << "Correct count of substrings: " << correct_count << endl;
    cout << "The resulting count of substrings: " << count << endl;
    return false;
  }
}

bool test_5() {
  string text = "hello hello hell";
  string substring = "world";

  int correct_count = 0;
  int count = search_for_all_substring(text, substring).size();

  if (count == correct_count) {
    return true;
  } else {
    cout << "Test 5 failed!" << endl;
    cout << "Correct count of substrings: " << correct_count << endl;
    cout << "The resulting count of substrings: " << count << endl;
    return false;
  }
}

void checking_tests() {
  int test_counter{};
  bool check;
  const int ALL_TESTS_PASSED{ 5 };

  if (test_1()) {
    test_counter++;
  }
  if (test_2()) {
    test_counter++;
  }
  if (test_3()) {
    test_counter++;
  }
  if (test_4()) {
    test_counter++;
  }
  if (test_5()) {
    test_counter++;
  }
  if (test_counter == ALL_TESTS_PASSED) {
    cout << "All tests passed successfully!" << endl;
  }
}