// UPDATE VERSION IN https://github.com/lucassalvino/myLibraries/tree/master/BasisForDeveloping
#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#define CONFIG_MAP_STRING_STRING_ITERATOR std::map<std::string,std::string>::iterator
#include "utility.h"
namespace BaseDeveloping {
class Config
{
public:
    static void verifyInstance();
    static std::string getConfig(std::string name);
    static void setConfig(std::string name, std::string value);
    static void setConfig(std::string name, int value);
    static void setConfig(std::string name, double value);
    static void setConfigUl(std::string name, unsigned int value);
    static void setPatchFile(std::string path);
    static std::string getPathFile();
    static void loadConfigFromFile();
    static void loadConfigFromFile(std::string filePath);
    static void saveConfig();
    static void saveConfig(std::string filePath);
    static void clean();
    static int getNumConfig();

    static int getConfigInt(std::string name);
    static unsigned int getConfigUnsignedInt(std::string name);
    static float getConfigFloat(std::string name);
    static double getConfigDouble(std::string name);
    static bool getConfigBool(std::string name);

    static bool verifyFileConfig();
private:
    Config();
    static Config* _config;
    std::map<std::string,std::string> config;
    std::string patchFile;
};
}
#endif // CONFIG_H
