#ifndef CAMERA_H_
#define CAMERA_H_

#include "Point.h"
#include "Plate.h"

class Camera {
    public:
        Point3D position;
        Point3D rotation;

    void setCamera();
    Camera(Point3D pos, Point3D rot);
    Camera(int x_pos, int y_pos, int z_pos);
    Camera();
};

#endif