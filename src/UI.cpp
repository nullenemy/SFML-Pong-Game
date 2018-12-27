//
// Created by nullenemy on 12/27/18.
//

#include "UI.h"
#include <iostream>
#include <string>
UI::UI() {
    init();
    scoreText1.setFillColor(sf::Color::White);
    scoreText2.setFillColor(sf::Color::White);
    scoreText1.setCharacterSize(30);
    scoreText2.setCharacterSize(30);
}

void UI::init() {
    score1 = 0;
    score2 = 0;
    scoreText1.setString(std::to_string(score1));
    scoreText2.setString(std::to_string(score2));
}