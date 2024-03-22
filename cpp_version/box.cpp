#include "box.h"
#include <iostream>

Box::Box(const std::size_t grid_width, const std::size_t grid_height)
  : grid_width(grid_width), grid_height(grid_height){
  storage = new bool [grid_width * grid_height];
  
  //Initialize
  for(int i=0; i < grid_width * grid_height; i++){
    storage[i] = false;
  }

  ChangeColor(0, 0);
}

Box::~Box(){
  delete[] storage;
}

bool Box::IsBlack(const int x, const int y){
  if(0 <= x && x < grid_width && 0 <= y && y < grid_height){
    return storage[x + grid_width * y];
  }else{
    return false;
  }
}

void Box::ChangeColor(const int x, const int y){
  if(IsBlack(x, y) == true){
    storage[x + grid_width * y] = false;
  }else{
    storage[x + grid_width * y] = true;
  }
}

void Box::Update(){
  int counter;

  for(int i=0; i < grid_height; i++){
    for(int j=0; j < grid_width; j++){
      counter = 0;

      //Count around blacks
      if(IsBlack(j-1, i-1) == true){
        counter++;
      }
      if(IsBlack(j-1,i) == true){
        counter++;
      }
      if(IsBlack(j-1, i+1) == true){
        counter++;
      }
      if(IsBlack(j, i-1) == true){
        counter++;
      }
      if(IsBlack(j, i+1) == true){
        counter++;
      }
      if(IsBlack(j+1, i-1) == true){
        counter++;
      }
      if(IsBlack(j+1, i) == true){
        counter++;
      }
      if(IsBlack(j+1, i+1) == true){
        counter++;
      }

      //ChangeColor
      if(IsBlack(j, i) == true && counter >= 5){
        ChangeColor(j, i);
      }
      
      if(IsBlack(j ,i) == false && (counter <= 1 || counter >= 4)){
        ChangeColor(j,i);
      }

      

    }
  }
}