#include "controller.h"

Controller::Controller(const std::size_t grid_width, const std::size_t grid_height)
  : grid_width(grid_width), grid_height(grid_height) {
  
}

void Controller::ChangeBox(){

}

void Controller::HandleInput(bool &running){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }
  }
}