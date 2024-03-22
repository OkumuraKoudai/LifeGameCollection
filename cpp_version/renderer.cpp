#include "renderer.h"
#include "box.h"
#include <iostream>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height, 
                   const std::size_t grid_width, const std::size_t grid_height)
  : screen_width(screen_width), screen_height(screen_height), 
    grid_width(grid_width), grid_height(grid_height) {

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("LifeGame", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer(){
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Box &box){
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(sdl_renderer);

  //Render Box
  for(int i=0; i < grid_height; i++){
    block.y = i * block.h;
    for(int j=0; j < grid_width; j++){
      block.x = j * block.w;
      
      if(box.IsBlack(j, i) == true){
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(sdl_renderer, &block);
      }else{
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(sdl_renderer, &block);
      }
    }
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int number_black, int number_white, int fps){
  std::string title{"Lifegame   Black:" + std::to_string(number_black) + " White:" + std::to_string(number_white) + " FPS:"+ std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}