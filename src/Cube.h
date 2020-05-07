#ifndef CUBE_H_
#define CUBE_H_

#include "Point.h"
#include "Plate.h"
#include "Camera.h"
#include <stdlib.h>

class Cube
{
  public:
    Plate *plates;

  Cube(Point3D front[4], Point3D back[4]);
  Cube(Point3D p[8]);
  Cube(Plate p[6]);
  Cube(int cube_size);
  Cube();
  ~Cube();
  Cube operator/(const int scale) ;
  Cube operator*(const int scale) ;
  void Move(float x, float y, float z) ;
  void Rotate(float x, float y, float z) ;
  void Scale(float x, float y, float z) ;
  void PlatesRender();
  void PlatesDisplay();
};

#endif