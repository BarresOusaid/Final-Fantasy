#include "Services.hpp"
		  
  Services::Services (Map *map){
    this->map = map;
  }

  int const Services::getCellCount (){
  	return map->getWidth() * map->getHeight();
  }

  bool const Services::findFree (int& x, int& y){
  	for(int j =0; j<map->getHeight();j++){
  		for (int i = 0; i < map->getWidth(); ++i){
  			if(map->getType(i,j) == EmptySpace){
  				x = i;
  				x = j;
  				return true;
  			}	
  		}
  	}

  	return false; 
  } 

  int const Services::countEmptyRec (int x, int y, int id){
    if ( x<0 || x >= map->getWidth() || y<0 || y >= map->getHeight())
        return 0;

    map->initMetaData(id,0);
    return countEmptyRecSub(x,y,id);
  }

  int Services::countEmptyRecSub(int x, int y, int id, DIRECTION direction ){
    int count = 0;
    map->updateCoords(x,y);
    map->setMetaData(x,y,id,1);

    for (DIRECTION direction : directions){
        if(map->getType(x,y,direction) == EmptySpace 
           && map->getMetaData(x,y,id,direction) == 0){
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
      Type type = map->getType(x,y,d);

      if (type != EmptySpace){
        return false; 
      }
          
      int a = map->getMetaData(x,y,id);
      int b = map->getMetaData(x,y,id,d);

      /*il faut que je mette en oeuvre la direction car tous marche mais le b il faut le mettre en ouevre 
      grace a Coords voila voila*/
      
      std::cout << "relax: "<< std::endl;
      if ((a+1)< b){
          std::cout << "relax if" << std::endl;
          map->setMetaData(x,y,id,a+1,d);
          return a+1;
      }
      return 0;
  }

  void Services::ford (int x, int y, int id){
        map->initMetaData(id,99);
        map->setMetaData(x,y,id,0);
        bool cont = true;
        while(cont){
          cont =  false;
          for (int j = 0; j < map->getHeight(); ++j){
             for (int i = 0; i < map->getWidth(); ++i){
              for (DIRECTION direction : directions){
                if (map->isValid(i,j,direction)){
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