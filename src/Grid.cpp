/*
#include "Grid.hpp"

  Grid::Grid (){
    
    mapGrid = new Map();
    int * tabMap = mapGrid->getTabMap ();

  	for (int i = 0; i < height; ++i){
  		for (int j = 0; j < width; ++j){
  			grid[i][j] = tabMap[i];
  		}
  	}
  }

  Grid::~Grid (){

  }

  int const Grid::getWidth (){
  	return width;
  }

  int const Grid::getHeight (){
  	return height;
  }

  bool const Grid::isValid (int x, int y, DIRECTION d){
  	if (x < height && y < width){
  		return true;
  	}
  	else 
  		return false;
  }

  bool const Grid::updateCoords (int& x, int& y, DIRECTION d){
  	if (x < height && y < width){
  	 	this -> x = x;
      this -> y = y;
  		return true;
  	}
  	else 
  		return false;
  }

  Type const Grid::getType (int x, int y, DIRECTION d){
    if (isValid(x,y,d)){
           if (grid[x][y]==2 || grid[x][y]==0 || grid[x][y]==111 || grid[x][y]==107 || grid[x][y]==106){
              return EmptySpace;
           }
           else return FullSpace;
    }
    else return Invalid;
  }
  
  void Grid::initMetaData (int id, int value){
    metaData[height*width];
    for (int i = 0; i < height*width; ++i)
    {
      metaData[i] = value;
    }
  }

  int const Grid::getMetaData (int x, int y, int id, DIRECTION d){
    metaData[id] = grid[x][y];
    return metaData[id]; 
  }

  void Grid::setMetaData (int x, int y, int id, int value, DIRECTION d){
     metaData[id] = value;
     grid[x][y] = metaData[id]; 
  }
*/