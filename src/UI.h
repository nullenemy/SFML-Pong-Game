//
// Created by nullenemy on 12/27/18.
//

#ifndef SFML_PONG_GAME_UI_H
#define SFML_PONG_GAME_UI_H


#include <SFML/Graphics/Text.hpp>

class UI {
public:
    UI();
    int score1;
    int score2;
    sf::Text scoreText1;
    sf::Text scoreText2;

    void init();
};


#endif //SFML_PONG_GAME_UI_H
