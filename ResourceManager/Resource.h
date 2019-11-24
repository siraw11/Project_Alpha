//
// Created by Luca Graziotti on 24/11/2019.
//

#ifndef MOTOCROSS2D_RESOURCE_H
#define MOTOCROSS2D_RESOURCE_H


#include <iostream>
#include "ResourceManagerException.h"

class Resource {
private:
    std::string name;
    std::string filePath;
public:
    Resource(const std::string &name, const std::string &filePath);

    virtual ~Resource();


    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getFilePath() const;

    void setFilePath(const std::string &filePath);

};


#endif //MOTOCROSS2D_RESOURCE_H
