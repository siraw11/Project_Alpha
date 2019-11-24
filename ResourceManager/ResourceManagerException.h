//
// Created by Luca Graziotti on 24/11/2019.
//

#ifndef MOTOCROSS2D_RESOURCEMANAGEREXCEPTION_H
#define MOTOCROSS2D_RESOURCEMANAGEREXCEPTION_H

#include <iostream>

class ResourceManagerException : public std::exception {
private:
    std::string msg;
public:
    const std::string &getMsg() const;

    virtual ~ResourceManagerException();

    ResourceManagerException(const std::string &msg);
};


#endif //MOTOCROSS2D_RESOURCEMANAGEREXCEPTION_H
