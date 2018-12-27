#include "Game.h"
#include "StartState.h"
int main()
{
    Game game;
    StartState startState(&game);
    std::cout << startState.name << std::endl;
    game.pushState(&startState);
    game.gameLoop();

    return EXIT_SUCCESS;
}