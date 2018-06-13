#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdarg.h>

using namespace std;

class Utils
{
public:
    Utils();
    static string readFile(const string &path);
};

#endif // UTILS_H
