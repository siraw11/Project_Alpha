//
// Created by Luca Graziotti on 24/11/2019.
//

#include "ResourceManagerException.h"

ResourceManagerException::ResourceManagerException(const std::string &_msg) : msg(_msg) {}

ResourceManagerException::~ResourceManagerException() {}

const std::string &ResourceManagerException::getMsg() const {
    return msg;
}
