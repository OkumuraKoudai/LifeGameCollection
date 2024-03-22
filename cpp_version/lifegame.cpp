#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "renderer.h"
#include "controller.h"
#include "game.h"
#include <iostream>

int main(void){
  constexpr std::size_t kFramePerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramePerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller(kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  return 0;
}