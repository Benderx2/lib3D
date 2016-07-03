#include "lib3D.h"
#include <stdarg.h>

// render(pointer to display, camera, number of meshes, mesh1, mesh2, mesh3, ..., meshn)
void render(wp_display* disp, camera* cam, unsigned int n, ...) {
	
	matrix4* view_matrix = vec3_lookatLH(cam->pos, cam->target, vec3_unitY());
	matrix4* projection_matrix = mat_perspectiveFOV_RH(0.78f, disp->w / disp->h, 0.01f, 1.0f);
	
	va_list args;
	va_start(args, n);
	matrix4 *mesh_mat_rot, *mesh_mat_trans, *mesh_mat_world, *mesh_mat_transform;
	matrix4 *tmp;
	mesh *cmesh;
	for(int i = 0; i < n; i++) {
		// get current mesh
		cmesh = va_arg(args, mesh*);
		// world matrix = rotation matrix * translation matrix
		mesh_mat_rot = mat_rot_yawpitchroll(cmesh->rot.x, cmesh->rot.y, cmesh->rot.z);
		mesh_mat_trans = mat_translation(cmesh->pos.x, cmesh->pos.y, cmesh->pos.z);
		mesh_mat_world = mat_multiply(mesh_mat_rot, mesh_mat_trans);
		
		// transformation matrix = world matrix * view matrix * projection matrix
		tmp = mat_multiply(mesh_mat_world, view_matrix);
		// Get the final transformation matrix. fucking c doesn't support operator overloading
		// so have to do this. i don't have the time to learn c++ fuck off please
		// thank you.
		mesh_mat_transform = mat_multiply(tmp, projection_matrix);
		
		// free everything else.
		free(mesh_mat_rot);
		free(mesh_mat_trans);
		free(mesh_mat_world);
		free(tmp);
		
		// Draw all vertices
		for(int j = 0; j < cmesh->n; j++) {
			vec2* point = vec3_project(disp, mesh_vecptr(cmesh, j), mesh_mat_transform);
			vec2_draw(disp, point); // Draw the vertex.
			free(point);
		}
		
		free(mesh_mat_transform);
	}
}