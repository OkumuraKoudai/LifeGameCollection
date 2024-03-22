#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SDL.h"
#include "Box.h"

class Controller{
  public:
    Controller(const std::size_t grid_width, const std::size_t grid_height);
    void HandleInput(bool &running);
    void ChangeBox();
  private:
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif //CONTROLLER_H