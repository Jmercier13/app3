#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void exec(string title, void (*f)(void));
string sep(char c='=', int len=80);
string header(string title);