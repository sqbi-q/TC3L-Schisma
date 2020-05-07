#include "Camera.h"

Point3D* camPosition;
Point3D* camRotation;

Camera::Camera(Point3D pos, Point3D rot){
	position = pos;
	rotation = rot;
}

/* Rotation default 0, 0, 0 */
Camera::Camera(int x_pos, int y_pos, int z_pos){
	position = Point3D(x_pos, y_pos, z_pos);
	rotation = Point3D(0, 0, 0);
}

/* Rotation default 0, 0, 0 */
/* Position default 0, 0, 0 */
Camera::Camera(){
	position = Point3D(0, 0, 0);
	rotation = Point3D(0, 0, 0);
}

void Camera::setCamera(){
	camPosition = &position;
	camRotation = &rotation;
}