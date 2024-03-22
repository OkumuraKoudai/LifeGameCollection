#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"

class Game {
  public:
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller &controller, Renderer &renderer, std::size_t time_duration);
    int GetNumberOfBlack() const;
    int GetNumberOfWhite() const;

  private:
    Box box;
  
    int number_black;
    int number_white;

    void Update();
};

#endif //GAME_H