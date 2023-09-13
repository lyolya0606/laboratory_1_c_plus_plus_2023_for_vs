//
// Created by lyolya on 06.09.2023.
//
#include <iostream>
#include <string>
#include <vector>
#include "substring_search.h"
#include "beginning.h"
#include "checking_errors.h"
#include "input.h"
#include "saving_files.h"


using namespace std;

enum input_choice {
  KEYBOARD_INPUT = 1,
  FILE_INPUT
};

int is_a_substring(string sentence, string substr, int position) {
  if (sentence.find(substr) != std::string::npos) {
    return sentence.find(substr, position);
  } else {
    return -1;
  }
}

vector<int> search_for_all_substring(string text, string substring) {
  const int IS_NOT_SUBSTRING{ -1 };
  vector<int> list_of_indexes{};
  int index_of_substring{ 0 };
  int position{ 0 };

  do {
    index_of_substring = is_a_substring(text, substring, position);
    position = index_of_substring + substring.length();
    if (index_of_substring == IS_NOT_SUBSTRING) {
      break;
    }
    list_of_indexes.push_back(index_of_substring);
  } while (true);

  return list_of_indexes;
}


void work_with_text() {
  int user_choice;
  bool stop;
  string text{};

  do {
    menu_work_text();
    user_choice = get_int();

    switch (user_choice) {

    case KEYBOARD_INPUT: {
      text = keyboard_input();
      stop = true;
    }
                       break;

    case FILE_INPUT: {
      text = file_input();
      stop = true;
    }
                   break;

    default:
      cout << "There is no such choice!" << endl;
      stop = false;
    }

  } while (!stop);


  saving_files_input(text, "input");

  string substring = substring_input();

  vector<int> list_of_indexes = search_for_all_substring(text, substring);

  int start{ 0 };
  string result;
  if (list_of_indexes.empty()) {
    cout << "\033[1;31m" << substring << " isn't a substring of the given text:(\033[0m" << endl;
    result = substring + " isn't a substring of the given text:(";
  } else {
    cout << "The substring " << substring << " was found " << list_of_indexes.size() << " times!!!" << endl;
    for (int index : list_of_indexes) {
      cout << text.substr(start, index - start) + "\033[1;32m"
        << text.substr(index, substring.length())
        << "\033[0m";
      start = index + substring.length();

    }
    cout << text.substr(start) << endl;
    result = "The substring " + substring + " was found " + to_string(list_of_indexes.size()) + " times!!!";
  }
  saving_files_input(result, "result");


}