//
// Created by nullenemy on 12/25/18.
//

#ifndef SFML_PONG_GAME_H
#define SFML_PONG_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"

class GameState;
class Game
{
public:
    Game();
    ~Game();

    void pushState(GameState* state);
    void popState();
    GameState* CurrentState();
    void gameLoop();
    sf::RenderWindow window;
    sf::Font font;
    std::string winner;
private:
    std::vector<GameState*> states;


};

//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <stdexcept>
//class Game
//{
//public:
//    Game();
//    void run();
//private:
//    void processEvents();
//    void update(sf::Time timePerFrame);
//    void render();
//    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
//private:
//    int score1;
//    int score2;
//    const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
//    sf::Font font;
//    sf::RenderWindow mWindow;
//    sf::Text title;
//    sf::Text scoreText1;
//    sf::Text scoreText2;
//    sf::RectangleShape leftPaddle;
//    sf::RectangleShape rightPaddle;
//    sf::RectangleShape ball;
//
//    bool leftPaddleUp;
//    bool leftPaddleDown;
//    bool rightPaddleUp;
//    bool rightPaddleDown;
//    bool playing;
//};


#endif //SFML_PONG_GAME_H
