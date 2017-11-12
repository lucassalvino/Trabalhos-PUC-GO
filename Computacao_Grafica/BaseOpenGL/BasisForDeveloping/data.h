// UPDATE VERSION IN https://github.com/lucassalvino/myLibraries/tree/master/BasisForDeveloping
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include "datatype.h"
namespace BaseDeveloping {
class Data
{
public:
    static void verifyInstance();
    static void clear();
    static void saveData();
    static void loadData();
    static DataType* getData(std::string name);
    static void addData(DataType* value);
    static void removeData(std::string name);
private:
    Data();
    static Data* _data;
    std::vector<DataType*> data;
};
}
#endif // DATA_H
