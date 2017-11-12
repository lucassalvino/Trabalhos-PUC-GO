#include "config.h"
BaseDeveloping::Config* BaseDeveloping::Config::_config = 0;

BaseDeveloping::Config::Config()
{
    patchFile = "config.conf";
    config.clear();
}

void BaseDeveloping::Config::clean(){
    delete[] _config;
    _config = 0;
}

int BaseDeveloping::Config::getNumConfig()
{
    verifyInstance();
    return _config->config.size();
}

int BaseDeveloping::Config::getConfigInt(std::string name)
{
    return Utility::Convert::ToInt(Config::getConfig(name));
}

unsigned int BaseDeveloping::Config::getConfigUnsignedInt(std::string name)
{
    return std::stoul(Config::getConfig(name),nullptr,0);
}

float BaseDeveloping::Config::getConfigFloat(std::string name)
{
    return Utility::Convert::ToFloat(Config::getConfig(name));
}

double BaseDeveloping::Config::getConfigDouble(std::string name)
{
    return Utility::Convert::ToDouble(Config::getConfig(name));
}

bool BaseDeveloping::Config::getConfigBool(std::string name)
{
    return Utility::Convert::ToInt(Config::getConfig(name));
}

bool BaseDeveloping::Config::verifyFileConfig()
{
    verifyInstance();
    FILE* arq = fopen(_config->patchFile.c_str(),"r");
    if(arq){
        fclose(arq);
        return true;
    }else{
        arq = fopen(_config->patchFile.c_str(),"w");
        if(arq){
            fclose(arq);
            return true;
        }
    }
    return false;
}

void BaseDeveloping::Config::verifyInstance(){
    if(_config == 0){
        _config = new Config();
    }
}

std::string BaseDeveloping::Config::getConfig(std::string name)
{
    verifyInstance();
    CONFIG_MAP_STRING_STRING_ITERATOR it = _config->config.begin();
    for(;it !=_config->config.end() ;it++){
        if(it->first == name) return it ->second;
    }
    throw std::string(std::string(std::string("not found [")+name+std::string("]")));
}

void BaseDeveloping::Config::setConfig(std::string name, std::string value){
    verifyInstance();
    _config->config[name] = value;
}

void BaseDeveloping::Config::setConfig(std::string name, int value)
{
    verifyInstance();
    _config->config[name] = Utility::Convert::ToString(value);
}

void BaseDeveloping::Config::setConfig(std::string name, double value)
{
    verifyInstance();
    _config->config[name] = Utility::Convert::ToString(value);
}

void BaseDeveloping::Config::setConfigUl(std::string name, unsigned int value)
{
    verifyInstance();
    _config->config[name] = std::to_string(value);
}

void BaseDeveloping::Config::setPatchFile(std::string path){
    verifyInstance();
    _config->patchFile = path;
}

std::string BaseDeveloping::Config::getPathFile()
{
    verifyInstance();
    return _config->patchFile;
}

void BaseDeveloping::Config::loadConfigFromFile()
{
    verifyInstance();
    FILE* arq = fopen(_config->patchFile.c_str(),"r");
    if(arq == 0){
        throw std::string(std::string("File ["+_config->patchFile+"] not found"));
    }
    char name[90];
    char value[250];
    while(*name = *value = 0, fscanf(arq," %[^:]:%[^\n]\n",name,value)!=-1){
        _config->config[std::string(name)] = std::string(value);
    }
    fclose(arq);
}

void BaseDeveloping::Config::loadConfigFromFile(std::string filePath)
{
    Config::setPatchFile(filePath);
    Config::loadConfigFromFile();
}

void BaseDeveloping::Config::saveConfig()
{
    verifyInstance();
    FILE* arq = fopen(_config->patchFile.c_str(),"w");
    if(arq == 0){
        throw std::string(std::string("File ["+_config->patchFile+"] not available"));
    }
    CONFIG_MAP_STRING_STRING_ITERATOR it = _config->config.begin();
    for(;it !=_config->config.end() ;it++){
        fprintf(arq,"%s:%s\n",it->first.c_str(),it->second.c_str());
    }
    fclose(arq);
}

void BaseDeveloping::Config::saveConfig(std::string filePath)
{
    Config::setPatchFile(filePath);
    Config::saveConfig();
}
