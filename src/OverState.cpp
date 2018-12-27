//
// Created by nullenemy on 12/27/18.
//

#include "OverState.h"

OverState::OverState(Game* game) {
    this->name = "Game Over";
    this->game = game;
    gameOver.setCharacterSize(30);
    gameOver.setFillColor(sf::Color::White);
    restart.setCharacterSize(30);
    restart.setFillColor(sf::Color::White);
}

void OverState::draw(float dt){
    game->window.draw(gameOver);
}

void OverState::update(const float dt) {

}

void OverState::handleInput() {
    sf::Event event;
    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this->game->window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Return)
                    restartGame();

                break;
        }
    }
}

void OverState::restartGame() {
    this->game->popState();
    std::cout <<  this->game->CurrentState()->name << std::endl;
}

