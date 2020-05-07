#include "Cube.h"

void initPlates(Plate plates[6], int cube_size){
    plates[0] = Plate(Point3D(-cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, cube_size), Point3D(-cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, cube_size));
	plates[1] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(-cube_size, -cube_size, -cube_size), Point3D(cube_size, -cube_size, -cube_size));
	plates[2] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(-cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, cube_size));
	plates[3] = Plate(Point3D(-cube_size, -cube_size, -cube_size), Point3D(cube_size, -cube_size, -cube_size), Point3D(-cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, cube_size));
	plates[4] = Plate(Point3D(-cube_size, cube_size, -cube_size), Point3D(-cube_size, cube_size, cube_size), Point3D(-cube_size, -cube_size, -cube_size), Point3D(-cube_size, -cube_size, cube_size));
	plates[4] = Plate(Point3D(cube_size, cube_size, cube_size), Point3D(cube_size, cube_size, -cube_size), Point3D(cube_size, -cube_size, cube_size), Point3D(cube_size, -cube_size, -cube_size));
}

Cube::Cube(Point3D front[4], Point3D back[4]){

}

Cube::Cube(Point3D p[8]){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    plates[0] = Plate(p[0], p[1], p[2], p[3]);
	plates[1] = Plate(p[4], p[5], p[6], p[7]);
	plates[2] = Plate(p[4], p[5], p[0], p[1]);
	plates[3] = Plate(p[6], p[7], p[2], p[3]);
	plates[4] = Plate(p[4], p[0], p[6], p[2]);
	plates[4] = Plate(p[1], p[5], p[3], p[7]);
}

Cube::Cube(Plate p[6]){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    plates = p;
}

Cube::Cube(int cube_size){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    initPlates(plates, cube_size);
}

Cube::Cube(){
    plates = (Plate*) malloc(6 * sizeof(Plate));
    initPlates(plates, 50);
}

Cube::~Cube(){
    free(plates);
}

void Cube::Move(float x, float y, float z){
    for(int i=0; i<6; i++){
        plates[i].setPosition(plates[i].getPosition()+Point3D(x, y, z));
    }
}

void Cube::Rotate(float x, float y, float z){
    for(int i=0; i<6; i++){
        plates[i].setRotation(plates[i].getRotation()+Point3D(x, y, z));
    }
}

void Cube::Scale(float x, float y, float z){
    for(int i=0; i<6; i++){
        //todo
    }
}

void Cube::PlatesRender(){
    for(int i=0; i<6; i++){
        plates[i].render();
    }
}
void Cube::PlatesDisplay(){
    for(int i=0; i<6; i++){
        plates[i].display();
    }
}