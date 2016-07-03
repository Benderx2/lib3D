#include "raster.h"

void rs_draw_line(wp_display* disp, int x0, int y0, int x1, int y1, int r, int g, int b, int a) {
	int dx = abs(x1-x0);
	int dy = abs(y1-y0); 
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1; 
	int err = ((dx > dy) ? dx : -dy)/2;
	int e2 = err;
	for(;;){
		wp_pixel(disp, x0, y0, r, g, b, a);
		if (x0 == x1 && y0 == y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}
void rs_draw_triangle(wp_display* disp, vec2* p1, vec2* p2, vec2* p3, int r, int g, int b, int a) {
	rs_draw_line(disp, p1->x, p1->y, p2->x, p2->y, r, g, b, a);
	rs_draw_line(disp, p2->x, p2->y, p3->x, p3->y, r, g, b, a);
	rs_draw_line(disp, p3->x, p3->y, p1->x, p1->y, r, g, b, a);
}
void rs_draw_quad(wp_display* disp, vec2* p1, vec2* p2, vec2* p3, vec2* p4, int r, int g, int b, int a) {
	rs_draw_line(disp, p1->x, p1->y, p2->x, p2->y, r, g, b, a);
	rs_draw_line(disp, p2->x, p2->y, p3->x, p3->y, r, g, b, a);
	rs_draw_line(disp, p3->x, p3->y, p4->x, p4->y, r, g, b, a);
	rs_draw_line(disp, p4->x, p4->y, p1->x, p1->y, r, g, b, a);
}
void rs_draw_circle(wp_display* disp, int x0, int y0, int radius, int r, int g, int b, int a) {
	int x = radius;
	int y = 0;
	int err = 0;
	while (x >= y) {
		wp_pixel(disp, x0 + x, y0 + y, r, g, b, a);
		wp_pixel(disp, x0 + y, y0 + x, r, g, b, a);
		wp_pixel(disp, x0 - y, y0 + x, r, g, b, a);
		wp_pixel(disp, x0 - x, y0 + y, r, g, b, a);
		wp_pixel(disp, x0 - x, y0 - y, r, g, b, a);
		wp_pixel(disp, x0 - y, y0 - x, r, g, b, a);
		wp_pixel(disp, x0 + y, y0 - x, r, g, b, a);
		wp_pixel(disp, x0 + x, y0 - y, r, g, b, a);
		y += 1;
		err += 1 + 2*y;
		if (2*(err-x) + 1 > 0) {
            x -= 1;
            err += 1 - 2*x;
        }
    }
}
