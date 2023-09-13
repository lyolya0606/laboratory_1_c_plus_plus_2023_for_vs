//
// Created by lyolya on 12.09.2023.
//
#include <iostream>
#include <string>
#include <fstream>
#include "file_errors.h"
#include "checking_errors.h"

using namespace std;


void saving_files_input(string text, string type) {
  cout << endl << "Press 1 if you want to save your " << type << " in the file" << endl
    << "Press 2 if you DON'T want to save your " << type << " in the file" << endl;
  int choice = get_int();
  const int SAVING{ 1 };
  const int NOT_SAVING{ 2 };

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl << endl
      << "Press 1 if you want to save your " << type << " in the file" << endl
      << "Press 2 if you DON'T want to save your " << type << " in the file" << endl;

    choice = get_int();
  }

  if (choice == SAVING) {
    ofstream file = open_file_output();
    file << text;

    file.close();
    cout << "The data was successfully saved" << endl;
  }
}