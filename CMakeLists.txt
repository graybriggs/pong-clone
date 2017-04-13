cmake_minimum_required(VERSION 3.2)
project(pong-clone)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wextra -pedantic")

find_package(PkgConfig REQUIRED)
pkg_search_module(SDL REQUIRED sdl)

add_executable(pong-clone
  main.cpp
  game.cpp
  ball.cpp
  paddle_base.cpp
  paddle_players.cpp
  score.cpp
)

target_link_libraries(pong-clone PUBLIC
  ${SDL_LIBRARIES}
)

target_include_directories(pong-clone PUBLIC
  ${SDL_INCLUDE_DIR}
)