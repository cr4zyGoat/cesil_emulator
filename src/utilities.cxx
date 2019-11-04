#include "utilities.h"

Json::Value string2json(const char *str) {
    Json::Value result;
    std::stringstream sstr(str);
    sstr >> result;
    return result;
};

unsigned long hex2ulong(const char *str) {
    return std::strtoul(str, 0, 16);
};

std::string strip(std::string &str) {
    std::string bad_chars = "\t\n\v\f\r";
    str.erase(0, str.find_first_not_of(bad_chars));
    str.erase(str.find_last_not_of(bad_chars)+1);
    return str;
};