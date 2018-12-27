//
// Created by nullenemy on 12/26/18.
//

#include "StartState.h"
#include "PlayState.h"
#include <iostream>
StartState::StartState(Game *game) {
    this->game = game;
    this->name = "start";
    title.setString("Pong Game");
    title.setFont(game->font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(30);
    title.setPosition(game->window.getSize().x/2 - title.getLocalBounds().width/2,
                      game->window.getSize().y/2 - title.getLocalBounds().height/2);
}

void StartState::loadGame() {
    game->pushState(new PlayState(game));
}

void StartState::handleInput() {
    sf::Event event;
    while (game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                game->window.close();
                break;

                /* Change Between game states */
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    game->window.close();
                else if (event.key.code == sf::Keyboard::Return)
                    std::cout << "start game" << std::endl;
                    loadGame();
                break;
        }
    }
}

void StartState::update(const float dt) {

}

void StartState::draw(const float dt) {
    game->window.draw(title);

}

