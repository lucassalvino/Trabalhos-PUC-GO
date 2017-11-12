#include "datatype.h"

std::string BaseDeveloping::DataType::getName()
{
    return name;
}

void BaseDeveloping::DataType::setName(std::string value)
{
    name = value;
}

std::string BaseDeveloping::DataType::getDescription()
{
    return description;
}

void BaseDeveloping::DataType::setDescription(std::string value)
{
    description = value;
}

std::string BaseDeveloping::DataType::getPatchFile()
{
    return patchFile;
}

void BaseDeveloping::DataType::setPatchFile(std::string value)
{
    patchFile = value;
}
