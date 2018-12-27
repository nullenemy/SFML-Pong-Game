//
// Created by nullenemy on 12/26/18.
//

#ifndef SFML_PONG_GAME_PADDLE_H
#define SFML_PONG_GAME_PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
class Paddle: public sf::RectangleShape {
public:
    Paddle();

public:
    static const int width = 20;
    static const int height = 80;
    static const int speed = 400;

};


#endif //SFML_PONG_GAME_PADDLE_H
