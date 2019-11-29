//
// Created by Luca Graziotti on 28/11/2019.
//

#ifndef MOTOCROSS2D_RESOURCEMAP_H
#define MOTOCROSS2D_RESOURCEMAP_H


#include <Map.h>
#include "Resource.h"

class ResourceMap : public Resource {
public:
    ResourceMap(const std::string &name, const std::string &filePath);

    virtual ~ResourceMap();

    const std::shared_ptr<Map> &getMap() const;

    void setMap(const std::shared_ptr<Map> &map);

private:
    std::shared_ptr<Map> map = std::shared_ptr<Map>();

    static std::shared_ptr<Map> loadFromFile(std::string path);

    static std::string readFile(std::string filePath);

    static Position parseMapPoint(std::string pair);

    static std::list<Position> parseMapPoints(std::string raw);

    static std::list<Item *> parseMapItems(std::string raw);

    static Item *parseMapItem(std::string raw);

    static std::string split(std::string str, std::string l, std::string r);

    static std::vector<std::string> explode(std::string const &s, char delim);

};

#endif //MOTOCROSS2D_RESOURCEMAP_H
