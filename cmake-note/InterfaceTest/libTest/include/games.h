#pragma once

#include <stdio.h>
#include <string>

class games{
public:
    games(const std::string &favoriteGame="Prototype") : favoriteGame(favoriteGame)
    {

    }

    std::string myGame()
    {
        return favoriteGame;
    }
private:
    std::string favoriteGame;

};