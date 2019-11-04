#ifndef UTILITIES_H
#define UTILITIES_H

#include <json/json.h>

Json::Value string2json(const char *str);
unsigned long hex2ulong(const char *str);
std::string strip(std::string &str);

#endif