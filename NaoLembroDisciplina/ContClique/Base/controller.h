#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
class Controller
{
private:
    string ConfigPath;
    string SavePath;
public:
    Controller();
    void SetSavePath(string value);
    string GetSavePath();
    string GetConfigPath();
    void ClickAcao();
    void LoadConfig();
};

#endif // CONTROLLER_H
