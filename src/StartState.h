//
// Created by nullenemy on 12/26/18.
//

#ifndef SFML_PONG_GAME_STARTSTATE_H
#define SFML_PONG_GAME_STARTSTATE_H

#include "GameState.h"
#include "Game.h"
class StartState : public GameState {
public:
    StartState(Game* game);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

private:
    sf::View view;
    sf::Text title;
    void loadGame();
};


#endif //SFML_PONG_GAME_STARTSTATE_H
