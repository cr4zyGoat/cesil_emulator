#include "utilities.h"

Json::Value string_to_json(const char *str)
{
    Json::Value result;
    std::stringstream sstr(str);
    sstr >> result;
    return result;
}