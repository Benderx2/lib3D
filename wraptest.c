#include <stdio.h>
#include "lib3D.h"
#include "render.h"

int main(int argc, char** argv) {
	wp_init();
	wp_display* display = wp_create(640, 480, 32, "Test Engine");
	wp_apply(display);
	wp_event e;
	mesh* cube = mesh_create(8);
	mesh_add(cube, 0, -1, 1, 1);
	mesh_add(cube, 1, 1, 1, 1);
	mesh_add(cube, 2, 1, -1, 1);
	mesh_add(cube, 3, -1, -1, -1);
	mesh_add(cube, 4, 1, 1, -1);
	mesh_add(cube, 5, -1, -1, 1);
	mesh_add(cube, 6, 1, -1, -1);
	mesh_add(cube, 7, 1, 1, -1);
	camera cam;
	cam.pos = vec_create(0.0f, 0.0f, 10.0f, 0.0f, VEC3);
	cam.target = vec_create(0.0f, 0.0f, 0.0f, 0.0f, VEC3);
	unsigned int cur_count = 0;
	while(true) {
		wp_track(&e);
		if(cur_count == 0) {
			cur_count = e.count;
		}
		if(e.count > cur_count + 1000/60) {
			cur_count = e.count;
			wp_clear(display, 0, 0, 0, 1);
			render(display, &cam, 1, cube);
			vec3 new_pos, new_rot;
			
			new_pos.x = cube->pos.x+0.01f;
			new_pos.y = cube->pos.y+0.01f;
			new_pos.z = cube->pos.z+0.01f;
			
			new_rot.x = cube->rot.x+0.01f;
			new_rot.y = cube->rot.y+0.01f;
			new_rot.z = cube->rot.z+0.01f;
			
			mesh_property(cube, &new_pos, &new_rot);
			wp_update(display);
		}
		if(e.quit == true) {
			break;
		}
	}
	wp_quit(display, 0);
}