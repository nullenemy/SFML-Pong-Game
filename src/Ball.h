//
// Created by nullenemy on 12/27/18.
//

#ifndef SFML_PONG_GAME_BALL_H
#define SFML_PONG_GAME_BALL_H


enum Direction {
    LEFT,
    RIGHT
};



#include <SFML/Graphics/RectangleShape.hpp>
class Ball : public sf::RectangleShape {

public:
    Ball();
    void handleMove(float dt);
    void changeAngle();
    void changeSpeedAndAngle();
    static const int width = 20;
    static const int height = 20;
    int speed = 200;
    sf::Vector2f direction;
    float angle;

};


#endif //SFML_PONG_GAME_BALL_H
