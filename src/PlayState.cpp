//
// Created by nullenemy on 12/26/18.
//

#include "PlayState.h"
#include "Paddle.h"
#include "OverState.h"
#include <ctime>
#include <cstdlib>
#include <math.h>

void PlayState::draw(const float dt) {
    game->window.draw(leftPaddle);
    game->window.draw(rightPaddle);
    game->window.draw(ball);
    game->window.draw(ui.scoreText1);
    game->window.draw(ui.scoreText2);

    if(checkWinner() > 0){
        GameOver(checkWinner());
        ui.init();
    }

}

void PlayState::GameOver(int winner) {
    OverState* overState = new OverState(game);
    overState->gameOver.setString("Player " + std::to_string(winner) + " Won");
    overState->gameOver.setFont(game->font);
    overState->gameOver.setPosition(this->game->window.getSize().x / 2 - overState->gameOver.getLocalBounds().width / 2, 100);
    game->pushState(overState);
}



void PlayState::update(const float dt) {
    if(leftPaddleUp){
        leftPaddle.move(0, -leftPaddle.speed * dt);
        if(leftPaddle.getPosition().y < 0){
            leftPaddle.setPosition(leftPaddle.getPosition().x, 0);
        }
        leftPaddleUp = false;
    }
    if(leftPaddleDown){
        leftPaddle.move(0, leftPaddle.speed * dt);
        if(leftPaddle.getPosition().y > game->window.getSize().y - leftPaddle.getLocalBounds().height){
            leftPaddle.setPosition(leftPaddle.getPosition().x, game->window.getSize().y - leftPaddle.getLocalBounds().height);
        }
        leftPaddleDown = false;
    }

    if(rightPaddleDown){
        rightPaddle.move(0, rightPaddle.speed * dt);
        if(rightPaddle.getPosition().y > game->window.getSize().y - rightPaddle.getLocalBounds().height){
            rightPaddle.setPosition(rightPaddle.getPosition().x, game->window.getSize().y - rightPaddle.getLocalBounds().height);
        }
        rightPaddleDown = false;
    }

    if(rightPaddleUp) {
        rightPaddle.move(0, -rightPaddle.speed * dt);
        if(rightPaddle.getPosition().y < 0){
            rightPaddle.setPosition(rightPaddle.getPosition().x, 0);
        }

        rightPaddleUp = false;
    }
    ball.handleMove(dt);

    switch (willHitWall()){
        case TOP:
            ball.setPosition(ball.getPosition().x, 0);
            ball.direction.y *= -1.f;
            break;
        case BOTTOM:
            ball.setPosition(ball.getPosition().x, game->window.getSize().y - ball.getLocalBounds().height);
            ball.direction.y *= -1.f;
            break;

    }

    sf::FloatRect leftPaddleBox = leftPaddle.getGlobalBounds();

    sf::FloatRect rightPaddleBox = rightPaddle.getGlobalBounds();
    sf::FloatRect ballBox = ball.getGlobalBounds();

    if(willExitWorld()){
        ball.setPosition(game->window.getSize().x/2 - ball.width/2, game->window.getSize().y/2 - ball.height/2);
        ball.direction.x *= -1.f;
        ball.changeAngle();
        ui.scoreText1.setString(std::to_string(ui.score1));
        ui.scoreText2.setString(std::to_string(ui.score2));
    }
    else if(leftPaddleBox.intersects(ballBox)){
        std::cout << "left paddle collision" << std::endl;
        ball.direction.x *= -1.f;
        ball.setPosition(leftPaddle.getPosition().x + leftPaddle.getLocalBounds().width, ball.getPosition().y);
        ball.changeSpeedAndAngle();
    } else if(rightPaddleBox.intersects(ballBox)){
        std::cout << "right paddle collision" << std::endl;
        ball.direction.x *= -1.f;
        ball.setPosition(rightPaddle.getPosition().x - ball.getLocalBounds().width, ball.getPosition().y);
        ball.changeSpeedAndAngle();
    }
}

void PlayState::handleInput() {
    sf::Event event;
    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this->game->window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    PauseGame();
                if(event.key.code == sf::Keyboard::W)
                    leftPaddleUp = true;
                if(event.key.code == sf::Keyboard::S)
                    leftPaddleDown = true;
                if(event.key.code == sf::Keyboard::Up)
                    rightPaddleUp = true;
                if(event.key.code == sf::Keyboard::Down)
                    rightPaddleDown = true;
                break;
        }
    }
}


void PlayState::init() {
    leftPaddleUp = false;
    leftPaddleDown = false;
    rightPaddleDown = false;
    rightPaddleUp = false;
    leftPaddle.setPosition(10, game->window.getSize().y/2 - leftPaddle.height/2);
    rightPaddle.setPosition(game->window.getSize().x - 10 - leftPaddle.width,
                            game->window.getSize().y/2 - leftPaddle.height/2);
    ball.setPosition(game->window.getSize().x/2 - ball.width/2,
                     game->window.getSize().y/2 - ball.height/2);
    ui.scoreText1.setFont(game->font);
    ui.scoreText2.setFont(game->font);
    ui.scoreText1.setPosition(50, 50);
    ui.scoreText2.setPosition(game->window.getSize().x - 50 - ui.scoreText2.getLocalBounds().width, 50);
}

PlayState::PlayState(Game* game)
{

    this->game = game;
    this->name = "Play";
    this->init();
}

void PlayState::PauseGame()
{


}


bool PlayState::willExitWorld() {
    if(ball.getPosition().x < 10){
        ui.score2 += 1;
        return true;
    }
    else if(ball.getPosition().x > game->window.getSize().x - 10 - ball.width)
    {
        ui.score1 += 1;
        return true;
    }
    else
        return false;
}

HitPoint PlayState::willHitWall() {
    if(ball.getPosition().y > game->window.getSize().y - 20){
        return BOTTOM;
    } else if(ball.getPosition().y < 0){
        return TOP;
    } else {
        return NOHIT;
    }
}


int PlayState::checkWinner() {
    if(ui.score1 == 11){
        return 1;
    } else if(ui.score2 == 11){
        return 2;
    } else {
        return 0;
    }
}



