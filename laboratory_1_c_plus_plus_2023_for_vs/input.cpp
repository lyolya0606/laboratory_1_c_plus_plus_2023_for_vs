//
// Created by lyolya on 07.09.2023.
//
#include <iostream>
#include <string>
#include <fstream>
#include "checking_errors.h"

using namespace std;

ifstream open_file_input();

string file_input() {
  string text{};
  string str;
  ifstream file;

  file = open_file_input();

  while (!file.eof()) {
    getline(file, str);
    text += str;
  }
  cout << "Read data:" << endl << text << endl;

  file.close();
  return text;
}


string keyboard_input() {
  cout << endl << "Write the text:" << endl;
  string text{};
  getline(cin, text, '\n');
  return text;
}


string substring_input() {
  cout << endl << "Write the substring:" << endl;
  string text{};
  getline(cin, text, '\n');
  return text;
}
