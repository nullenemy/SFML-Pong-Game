cmake_minimum_required(VERSION 3.13)
project(SFML_Pong_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_Pong_Game src/main.cpp src/Game.cpp src/Game.h src/GameState.h src/StartState.cpp src/StartState.h src/PlayState.cpp src/PlayState.h src/Paddle.cpp src/Paddle.h src/Ball.cpp src/Ball.h src/UI.cpp src/UI.h src/OverState.cpp src/OverState.h)
target_link_libraries(SFML_Pong_Game -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system)
configure_file("resources/font.ttf" "${CMAKE_BINARY_DIR}/" COPYONLY)