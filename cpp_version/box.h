#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box {
  public:
    Box(const std::size_t grid_width, const std::size_t grid_height);
    ~Box();
    bool IsBlack(const int x, const int y);
    void ChangeColor(const int x, const int y);
    void Update();

  private:
    bool *storage;

    const std::size_t grid_width;
    const std::size_t grid_height;
};



#endif //BOX_H