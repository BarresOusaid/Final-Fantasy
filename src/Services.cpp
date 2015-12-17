#include "Services.hpp"
#include "Grid.hpp"
#include "Player.hpp"
#include "Grid.hpp"
#include "Map.hpp"
		  
  int const Services::getCellCount (){
  	return grid.getWidth() * grid.getHeight();
  }

  bool const Services::findFree (int& x, int& y){
  	for(int j =0; j<grid.getHeight();j++){
  		for (int i = 0; i < grid.getWidth(); ++i){
  			if(grid.getType(i,j) == EmptySpace){
  				x = i;
  				x = j;
  				return true;
  			}	
  		}
  	}

  	return false; 
  } 

  int const Services::countEmptyRec (int x, int y, int id){
    if ( x<0 || x >= grid.getWidth() || y<0 || y >= grid.getHeight())
        return 0;

    grid.initMetaData(id,0);
    return countEmptyRecSub(x,y,id);
  }

  int Services::countEmptyRecSub(int x, int y, int id, DIRECTION direction ){
    int count = 0;
    grid.updateCoords(x,y);
    grid.setMetaData(x,y,id,1);

    for (DIRECTION direction : directions){
        if(grid.getType(x,y,direction) == EmptySpace 
           && grid.getMetaData(x,y,id,direction) == 0){
              count += 1+countEmptyRecSub(x,y,id,NO);
        }
    }
    return count;
  }

  int const Services::countEmptyIte (int x, int y, int id){
     /* grid.initMetaData(id,0);

      stack<Coords> todo;*/

  }

  int Services::relax (int x, int y, int id, DIRECTION d){
      Type type = grid.getType(x,y,d);
      if (type != EmptySpace)
          return false;
      int a = grid.getMetaData(x,y,id);
      int b = grid.getMetaData(x,y,id,d);

      if ((a+1)<d){
          grid.setMetaData(x,y,id,a+1,d);
          return a+1;
      }
      return 0;
  }

  void Services::ford (int x, int y, int id){
        grid.initMetaData(id,99);
        grid.setMetaData(x,y,id,0);
        bool cont = true;

        while(cont){
          cont =  false;
          for (int j = 0; j < grid.getHeight(); ++j){
             for (int i = 0; i < grid.getWidth(); ++i){
              for (DIRECTION direction : directions){
                if (grid.isValid(i,j,direction)){
                  if (relax(i,j,id,direction)){
                     cont = true;
                  }  
                }
              }
            }
          }
        }
  }
  
  void Services::dijkstra (int x, int y, int id){
  }