#include "utils.h"


Utils::Utils()
{

}

string Utils::readFile(const string &path){
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
