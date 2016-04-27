//header for the menu
//Michael Krumdick

#ifndef MENU_H
#define MENU_H

#include "mln.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using std::string;
using std::map;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


void printHeader();
void printMarkov(string, int);
void printMainMenu();
void testMenu();
void test(string, int);
void markovInfo();
void algInfo();

#endif
