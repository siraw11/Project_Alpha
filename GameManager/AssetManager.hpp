#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Alpha
{
    class AssetManager//serve per caricare font e background
    {
    public:
        AssetManager() { }
        ~AssetManager() { }

        void LoadTexture(std::string name, std::string fileName);//carica una texture sulla rispettiva map
        sf::Texture &GetTexture(std::string name);//restituisce una texture caricata

        void LoadFont(std::string name, std::string fileName);//idem rispetto alle texture
        sf::Font &GetFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
