//
// Created by nullenemy on 12/27/18.
//

#ifndef SFML_PONG_GAME_OVERSTATE_H
#define SFML_PONG_GAME_OVERSTATE_H


#include "GameState.h"


class OverState : public GameState{
public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    OverState(Game* game);
    sf::Text gameOver;
    sf::Text restart;

private:
    void restartGame();
};


#endif //SFML_PONG_GAME_OVERSTATE_H
