//
// Created by nullenemy on 12/26/18.
//

#ifndef SFML_PONG_GAME_PLAYSTATE_H
#define SFML_PONG_GAME_PLAYSTATE_H

#include "GameState.h"
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "UI.h"

enum HitPoint{
    NOHIT,
    TOP,
    BOTTOM
};

class PlayState : public GameState {
public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
    PlayState(Game* game);

private:
    bool willExitWorld();
    HitPoint willHitWall();
    void PauseGame();
    int checkWinner();
    void GameOver(int winner);
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;
    bool leftPaddleUp;
    bool leftPaddleDown;
    bool rightPaddleUp;
    bool rightPaddleDown;
    UI ui;

    void init();
};


#endif //SFML_PONG_GAME_PLAYSTATE_H
