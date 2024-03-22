#include "game.h"
#include "box.h"
#include "controller.h"
#include "renderer.h"
#include <iostream>

Game::Game(const std::size_t grid_width, const std::size_t grid_height) 
  : box(grid_width, grid_height) {

}

void Game::Run(Controller &controller, Renderer &renderer, std::size_t time_duration){
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running);
    Update();
    renderer.Render(box);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle( 1, 1, frame_count); //neededit
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < time_duration) {
      SDL_Delay(time_duration - frame_duration);
    }
  }
}

void Game::Update(){
  box.Update();
}