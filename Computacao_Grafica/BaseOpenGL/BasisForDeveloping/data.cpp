#include "data.h"
BaseDeveloping::Data* BaseDeveloping::Data::_data = 0;
void BaseDeveloping::Data::verifyInstance()
{
    if(_data == 0){
        _data = new Data();
    }
}

void BaseDeveloping::Data::clear()
{
    delete [] _data;
    _data = 0;
}

void BaseDeveloping::Data::saveData()
{
    verifyInstance();
    std::vector<DataType*>::iterator it = _data->data.begin();
    for(;it != _data->data.end(); it++){
        (*it)->saveInFile();
    }
}

void BaseDeveloping::Data::loadData()
{
    verifyInstance();
    std::vector<DataType*>::iterator it = _data->data.begin();
    for(;it != _data->data.end(); it++){
        (*it)->loadFromFile();
    }
}

BaseDeveloping::DataType *BaseDeveloping::Data::getData(std::string name)
{
    verifyInstance();
    std::vector<DataType*>::iterator it = _data->data.begin();
    for(;it != _data->data.end(); it++){
        if((*it)->getName() == name) return (*it);
    }
    throw std::string(std::string("Data [")+name+std::string("] not found"));
}

void BaseDeveloping::Data::addData(DataType *value)
{
    verifyInstance();
    if(value == 0)throw std::string("undefined reference from value");
    Data::removeData(value->getName());
    _data->data.push_back(value);
}

void BaseDeveloping::Data::removeData(std::string name)
{
    verifyInstance();
    std::vector<DataType*>::iterator it = _data->data.begin();
    for(;it != _data->data.end(); it++){
        if((*it)->getName() == name) _data->data.erase(it);
    }
}

BaseDeveloping::Data::Data()
{
    _data = 0;
    data.clear();
}
