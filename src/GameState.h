//
// Created by nullenemy on 12/26/18.
//

#ifndef SFML_PONG_GAME_GAMESTATE_H
#define SFML_PONG_GAME_GAMESTATE_H

#include "Game.h"
class GameState
{
public:
    std::string name;
    Game* game;
    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};
#endif //SFML_PONG_GAME_GAMESTATE_H
