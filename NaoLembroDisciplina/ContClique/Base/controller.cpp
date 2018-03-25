#include "controller.h"

Controller::Controller()
{
    SavePath = "DefaultOutput.csv";
    ConfigPath = "Config/Config.txt";
    LoadConfig();
}

void Controller::SetSavePath(string value)
{
    if(value == "") throw "Value of SavePath is invalid";
    SavePath = value;
}

string Controller::GetSavePath()
{
    return SavePath;
}

string Controller::GetConfigPath()
{
    return ConfigPath;
}

void Controller::ClickAcao()
{
    FILE* arqs = fopen(SavePath.c_str(), "a");
    time_t t = time(0);
    tm* timePtr = localtime(&t);
    if(arqs == 0) throw string("Arquivo: ["+SavePath+"] não pode ser aberto");
    char save[500];
    * save = 0;
    sprintf(save,"%d/%d/%d %d:%d:%d",(int)(timePtr->tm_mday),(int)((timePtr->tm_mon)+1),(int)((timePtr->tm_year)+1900),(int)(timePtr->tm_hour),(int)(timePtr->tm_min),(int)(timePtr->tm_sec));
    fprintf(arqs, "%s\n", save);
    fclose(arqs);
}

void Controller::LoadConfig()
{
    FILE* arq = fopen(ConfigPath.c_str(), "r");
    if(arq == 0)
    {
        printf("[ERRO] Arquivo de configuracao nao existe no caminho [%s]", ConfigPath.c_str());
        return;
    }
    char path[5000];
    *path = 0;
    fscanf(arq, " %[^\n]", path);
    this->SetSavePath(string(path));
    fclose(arq);
}
