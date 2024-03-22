#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "Box.h"

class Renderer {
  public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height, 
             const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render(Box &box);
    void UpdateWindowTitle(int number_black, int number_white, int fps);

  private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};


#endif //RENDERER_H