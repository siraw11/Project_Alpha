//
// Created by Luca Graziotti on 28/11/2019.
//

#include "ResourceMap.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>
#include "TimeBonus.h"
#include "SpeedBonus.h"
#include "SpeedMalus.h"
#include "Coin.h"
#include "Checkpoint.h"

ResourceMap::ResourceMap(const std::string &_name, const std::string &_filePath) : Resource(_name, _filePath) {
    this->map = loadFromFile(_filePath);
}


ResourceMap::~ResourceMap() {}

const std::shared_ptr<Map> &ResourceMap::getMap() const {
    return map;
}

void ResourceMap::setMap(const std::shared_ptr<Map> &map) {
    ResourceMap::map = map;
}

std::shared_ptr<Map> ResourceMap::loadFromFile(std::string path) {
    std::unique_ptr<Map> loadedMap = std::unique_ptr<Map>(new Map());
    std::list<Item *> mapItems;


    std::istringstream dataStringStream(readFile(std::move(path)));
    std::string dataString = dataStringStream.str();

    try {
        loadedMap->setId(split(dataString, "ID[", "]"));
        loadedMap->setRecord(std::stod(split(dataString, "Record[", "]")));
        loadedMap->setName(split(dataString, "Name[", "]"));
        loadedMap->setIsCompleted(std::stoi(split(dataString, "Completed[", "]")));
        loadedMap->setIsUnlocked(std::stoi(split(dataString, "Unlocked[", "]")));

        loadedMap->setMapPoints(parseMapPoints(split(dataString, "Points[", "]")));
        loadedMap->setMapItems(parseMapItems(split(dataString, "Items[", "]")));
    } catch (ResourceManagerException e) {
        std::cout << "Cannot Load map at " << path << std::endl;
    }
    return loadedMap;
}

std::list<Position> ResourceMap::parseMapPoints(std::string dataStringPoints) {
    std::list<Position> mapPoints;
    std::stringstream ss(dataStringPoints);
    size_t pos = 0;
    std::string pointPair;
    std::string delimiter = "|";
    while ((pos = dataStringPoints.find(delimiter)) != std::string::npos) {
        pointPair = dataStringPoints.substr(0, pos);
        mapPoints.push_back(parseMapPoint(pointPair));
        dataStringPoints.erase(0, pos + delimiter.length());
    }
    mapPoints.push_back(parseMapPoint(dataStringPoints));//parse dell'ultimo punto
    return mapPoints;
}

Position ResourceMap::parseMapPoint(std::string raw) {
    Position mP;
    try {
        mP.posX = std::stof(raw.substr(0, raw.find(",")));
        mP.posY = std::stof(raw.substr(raw.find(",") + 1, std::string::npos));
        return mP;
    } catch (std::exception e) {
        std::cout << "Invalid Point" << std::endl;
        throw ResourceManagerException("Cannot Parse correctly the map");
    }
}

std::string ResourceMap::readFile(std::string filePath) {
    std::ifstream infile(filePath);
    std::string line;
    std::string total = "";
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!iss) {
            break;
        }
        total += line + "\n";
    }
    return total;
}


std::string ResourceMap::split(std::string str, std::string l, std::string r) {
    std::string res = "";
    try {
        str.erase(0, str.find(l) + l.length());
        res = str.substr(0, str.find(r));
        return res;
    } catch (std::exception) {
        return "";
    }
}

std::list<Item *> ResourceMap::parseMapItems(std::string dataStringItems) {
    std::list<Item *> mapItems;
    std::stringstream ss(dataStringItems);
    size_t pos = 0;
    std::string itemString;
    std::string delimiter = "|";
    while ((pos = dataStringItems.find(delimiter)) != std::string::npos) {
        itemString = dataStringItems.substr(0, pos);
        mapItems.push_back(parseMapItem(itemString));
        dataStringItems.erase(0, pos + delimiter.length());
    }
    mapItems.push_back(parseMapItem(dataStringItems));//parse dell'ultimo punto
    return mapItems;
}

Item *ResourceMap::parseMapItem(std::string raw) {
    auto exploded = explode(raw, ',');
    int type = std::stoi(exploded[0]);
    float x = std::stof(exploded[1]);
    float y = std::stof(exploded[2]);
    float w = std::stof(exploded[3]);
    float h = std::stof(exploded[4]);
    float a = std::stof(exploded[5]);

    Item *item;
    try {
        switch (type) {
            case 1:
                item = new Coin(x, y, w, h, a, std::stof(exploded[6]));//ok
                break;
            case 2:
                item = new SpeedBonus(x, y, w, h, a, std::stof(exploded[6]), std::stof(exploded[7]));
                break;
            case 3:
                item = new SpeedMalus(x, y, w, h, a, std::stof(exploded[6]));//ok
                break;
            case 4:
                item = new TimeBonus(x, y, w, h, a, std::stof(exploded[6]));
                break;
            case 5:
                item = new Checkpoint(x, y, w, h, a, std::stoi(exploded[6]));
                break;
            default:
                item = new Item();
                break;
        }

    } catch (std::exception e) {
        throw ResourceManagerException("Error parsing map points");
    }
    return item;
}

std::vector<std::string> ResourceMap::explode(std::string const &s, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);) {
        result.push_back(std::move(token));
    }

    return result;
}
