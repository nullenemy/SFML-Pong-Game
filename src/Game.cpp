//
// Created by nullenemy on 12/25/18.
//

#include "Game.h"
#include "GameState.h"
#include <iostream>
Game::Game() {
    window.create(sf::VideoMode(800, 600), "Pong Game");
    window.setFramerateLimit(60);
    font.loadFromFile("font.ttf");
}

void Game::pushState(GameState *state) {
    states.push_back(state);
    std::cout << "switch state to " + state->name << std::endl;
}

void Game::popState()
{

    states.back();
    delete states.back();
    states.pop_back();
}

Game::~Game()
{
    while (!states.empty())
        popState();
}

GameState* Game::CurrentState()
{
    if (states.empty())

        return nullptr;
    else

        return states.back();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        //control frame rate (you can ignore this stuff for now)
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        //exception handling
        if (CurrentState() != nullptr){

            //get user input for current game state
            CurrentState()->handleInput();

            //update anything neccessary
            CurrentState()->update(dt);

            //clear window
            window.clear();

            //draw anything in the current game state
            CurrentState()->draw(dt);

            window.display();
        }
    }
}
//const int PADDLE_OFFSET = 10;
//const int PADDLE_WIDTH = 20;
//const int PADDLE_HEIGHT = 80;
//const int WINDOW_WIDTH = 1280;
//const int WINDOW_HEIGHT = 720;
//const int BALL_WIDTH = 16;
//const int SCORE_OFFSET = 50;
//const int SCORE_POSITION_Y = 50;
//Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Pong"),
//               leftPaddle(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
//               rightPaddle(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)),
//               ball(sf::Vector2f(BALL_WIDTH, BALL_WIDTH)),
//               score1(0),
//               score2(0),
//               playing(false),
//               leftPaddleUp(false),
//               leftPaddleDown(false),
//               rightPaddleUp(false),
//               rightPaddleDown(false)
//{
//
//
//    if (!font.loadFromFile("font.ttf"))
//    {
//
//        throw "couldn't load the font file";
//    }
//
//    title.setFont(font);
//    title.setString("SFML Pong");
//    title.setCharacterSize(50);
//    title.setFillColor(sf::Color::White);
//    title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
//    title.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
//
//    leftPaddle.setFillColor(sf::Color::White);
//    rightPaddle.setFillColor(sf::Color::White);
//    scoreText1.setFont(font);
//    scoreText2.setFont(font);
//    scoreText1.setString(std::to_string(score1));
//    scoreText2.setString(std::to_string(score2));
//    scoreText1.setCharacterSize(30);
//    scoreText2.setCharacterSize(30);
//    scoreText1.setFillColor(sf::Color::White);
//    scoreText2.setFillColor(sf::Color::White);
//    scoreText1.setPosition(SCORE_OFFSET, SCORE_POSITION_Y);
//    scoreText2.setPosition(WINDOW_WIDTH - SCORE_OFFSET - scoreText2.getLocalBounds().width, SCORE_POSITION_Y);
//    ball.setFillColor(sf::Color::White);
//    leftPaddle.setPosition(PADDLE_OFFSET, WINDOW_HEIGHT / 2 - PADDLE_WIDTH / 2);
//    rightPaddle.setPosition(WINDOW_WIDTH - PADDLE_OFFSET - PADDLE_WIDTH, WINDOW_HEIGHT / 2 - PADDLE_WIDTH / 2);
//
//
//}
//
//void Game::run()
//{
//    sf::Clock clock;
//    sf::Time timeSinceLastUpdate = sf::Time::Zero;
//    while (mWindow.isOpen())
//    {
//        processEvents();
//        timeSinceLastUpdate += clock.restart();
//        while(timeSinceLastUpdate > TimePerFrame)
//        {
//            timeSinceLastUpdate -= TimePerFrame;
//            processEvents();
//            update(TimePerFrame);
//        }
//
//        render();
//    }
//}
//
//void Game::processEvents()
//{
//    sf::Event event;
//    while (mWindow.pollEvent(event))
//    {
//        if(event.type == sf::Event::Closed){
//            mWindow.close();
//        }
//
//    }
//    if(playing)
//    {
//
//        switch (event.type)
//        {
//            case sf::Event::KeyPressed:
//                handlePlayerInput(event.key.code, true);
//                break;
//            case sf::Event::KeyReleased:
//                handlePlayerInput(event.key.code, false);
//                break;
//        }
//    }
//}
//
//
//void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
//{
//    if (key == sf::Keyboard::W)
//        leftPaddleUp = isPressed;
//    if (key == sf::Keyboard::S)
//        leftPaddleDown = isPressed;
//    if (key == sf::Keyboard::Up)
//        rightPaddleUp = isPressed;
//    if (key == sf::Keyboard::Down)
//        rightPaddleDown = isPressed;
//
//}
//void Game::update(sf::Time timePerFrame)
//{
//    if (leftPaddleUp)
//        leftPaddle.move(0.f, -300.f * timePerFrame.asSeconds());
//    if (leftPaddleDown)
//        leftPaddle.move(0.f, 300.f * timePerFrame.asSeconds());
//}
//
//void Game::render()
//{
//    mWindow.clear();
//    mWindow.draw(title);
//    mWindow.draw(scoreText1);
//    mWindow.draw(scoreText2);
//    mWindow.draw(leftPaddle);
//    mWindow.draw(rightPaddle);
//    mWindow.display();
//}