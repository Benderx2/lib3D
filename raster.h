#ifndef RASTER_H
#define RASTER_H

#include <math.h>

#include "vector.h"
#include "wrapper.h"

void rs_draw_line(wp_display* disp, int x0, int y0, int x1, int y1, int r, int g, int b, int a);
void rs_draw_circle(wp_display* disp, int x0, int y0, int radius, int r, int g, int b, int a);

void rs_draw_triangle(wp_display* disp, vec2* p1, vec2* p2, vec2* p3, int r, int g, int b, int a);
void rs_draw_quad(wp_display* disp, vec2* p1, vec2* p2, vec2* p3, vec2* p4, int r, int g, int b, int a);

#endif