//
// Created by nullenemy on 12/27/18.
//

#include "Ball.h"
#include <ctime>
#include <cstdlib>
#include <math.h>
#define PI 3.14159265

float RandomFloat(float a, float b)
{
    std::srand(std::time(nullptr));
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float RandomAngle(){
    float MAX_ANGLE = 60.f;
    float MIN_ANGLE = 30.f;
    return RandomFloat(MIN_ANGLE, MAX_ANGLE) * PI / 180;
}

Ball::Ball(){

    angle = RandomAngle();
    direction.x = 1.0f;
    direction.y = 1.0f;
    this->setSize(sf::Vector2f(width, height));
    this->setFillColor(sf::Color::White);
}

void Ball::changeAngle() {
    angle = RandomAngle();
    speed = 200;
}

void Ball::changeSpeedAndAngle(){
    speed *= RandomFloat(1.1, 1.3);
    angle *= RandomFloat(0.8, 1.2);
}

void Ball::handleMove(float dt) {
    this->move(speed*dt*cos(angle)*direction.x, speed*dt*sin(angle)*direction.y);
}

