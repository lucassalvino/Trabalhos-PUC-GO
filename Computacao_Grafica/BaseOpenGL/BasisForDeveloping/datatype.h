// UPDATE VERSION IN https://github.com/lucassalvino/myLibraries/tree/master/BasisForDeveloping
#ifndef DATATYPE_H
#define DATATYPE_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
namespace BaseDeveloping {
class DataType{
public:
    DataType(){}
    virtual ~DataType(){}
    virtual void saveInFile(){throw std::string("method [saveInFile] has not yet been implemented");}
    virtual void loadFromFile(){throw std::string("method [loadFromFile] has not yet been implemented");}
    virtual void clear(){throw std::string("method [clear] has not yet been implemented");}
    virtual void init(){throw std::string("method [init] has not yet been implemented");}
    std::string getName();
    void setName(std::string value);
    std::string getDescription();
    void setDescription(std::string value);
    std::string getPatchFile();
    void setPatchFile(std::string value);
protected:
    std::string name;
    std::string description;
    std::string patchFile;
};
}
#endif // DATATYPE_H
