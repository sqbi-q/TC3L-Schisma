#include <iostream>
#include <string.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "src/Point.h"
#include "src/primitives.h"
#include "src/Plate.h"
#include "src/Cube.h"

using namespace std;

struct {
	int vertical;
	int horizontal;
} Movement;

int main()
{
	initGraphics(1600, 900);
	Camera MainCamera = Camera(Point3D(0, 0, 0), Point3D(0, 0, 0));
	MainCamera.setCamera();

	//if int in constructor argument - it's size of points apart from each other
	Cube *cube[5] = {new Cube(30), new Cube(30), new Cube(30), new Cube(30), new Cube(30)};
	for(int i=0; i<3; i++){
		cube[i]->Move(i*60, 0, 0);
	}
	for(int i=3; i<5; i++){
		cube[i]->Move(60, (i-2)*60, 0);
	}

	cout << "TC3L Test" << endl;


	XSelectInput(di, wi, KeyPressMask | KeyReleaseMask | ExposureMask | PointerMotionMask);
	XEvent ev;
	XMotionEvent myszelel;
	XKeyEvent bieg;
	fd_set in_fds;
	struct timeval tv;

	XMapWindow(di, wi);
    XFlush(di);
    int x11_fd = ConnectionNumber(di);
	
	int quit = 0;
	while (!quit)
	{
		// Create a File Description Set containing x11_fd
        FD_ZERO(&in_fds);
        FD_SET(x11_fd, &in_fds);

        // Set our timer.  One second sounds good.
        tv.tv_usec = 10000;
        tv.tv_sec = 0;

        // Wait for X Event or a Timer
        int num_ready_fds = select(x11_fd + 1, &in_fds, NULL, NULL, &tv);
        if (num_ready_fds > 0) 
            printf("Event Received!\n");
        if (num_ready_fds == 0){
            // Handle timer here

			/*38 a
			40 d
			25 w
			39 s*/
			int walking_speed = 5;

			if(Movement.vertical > 0){
				MainCamera.position.x -= sin(MainCamera.rotation.y)*walking_speed;
				MainCamera.position.z += cos(MainCamera.rotation.y)*walking_speed;
			}
			else if(Movement.vertical < 0){
				MainCamera.position.x += sin(MainCamera.rotation.y)*walking_speed;
				MainCamera.position.z -= cos(MainCamera.rotation.y)*walking_speed;
			}

			if(Movement.horizontal > 0){
				MainCamera.position.x -= sin(MainCamera.rotation.z) + cos(MainCamera.rotation.y)*walking_speed;
				MainCamera.position.z += cos(MainCamera.rotation.z) - sin(MainCamera.rotation.y)*walking_speed;
			}
			else if(Movement.horizontal < 0){
				MainCamera.position.x += sin(MainCamera.rotation.z) + cos(MainCamera.rotation.y)*walking_speed;
				MainCamera.position.z -= cos(MainCamera.rotation.z) - sin(MainCamera.rotation.y)*walking_speed;
			}
			XClearWindow(di, wi) ;

			for(int i=0; i<5; i++){
					cube[i]->PlatesRender();
					cube[i]->PlatesDisplay();
			}
		}
        else if (num_ready_fds < 0) printf("An error occured!\n");

        // Handle XEvents and flush the input 
        while(XPending(di)){
            XNextEvent(di, &ev);
			if (ev.type == Expose)
			{
				for(int i=0; i<5; i++){
					cube[i]->PlatesRender();
					cube[i]->PlatesDisplay();
				}
			}

			if(ev.type == MotionNotify)
			{
				myszelel = ev.xmotion ;
				float x = myszelel.x_root;
				float y = myszelel.y_root;
				MainCamera.rotation.y = (960-x)/300 ;
				MainCamera.rotation.x = (y-540)/300 ;
				double dump = 0 ;
				XClearWindow(di, wi) ;

				for(int i=0; i<5; i++){
					cube[i]->PlatesRender();
					cube[i]->PlatesDisplay();
				}
			}
			if (ev.type == KeyPress)
			{
				switch(ev.xkey.keycode){
					// exit on ESC key press 
					case 0x09:
						quit = 1;
						break;
					case 25: //w
						Movement.vertical = 1;
						break;
					case 39: //s
						Movement.vertical = -1;
						break;
					case 38: //a
						Movement.horizontal = 1;
						break;
					case 40: //d
						Movement.horizontal = -1;
						break;
				}
			}
			else if (ev.type == KeyRelease)
			{
				switch(ev.xkey.keycode){
					case 25: //w
					case 39: //s
						Movement.vertical = 0;
						break;
					case 38: //a
					case 40: //d
						Movement.horizontal = 0;
				}
			}
		}
	}
	

	return 0;
}
