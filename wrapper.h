#ifndef _WRAPPER_H
#define _WRAPPER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL/SDL.h>


typedef struct {
	SDL_Surface* buffer;
	uint32_t h;
	uint32_t w;
	uint32_t bpp;
	char* title;
} wp_display;

typedef struct {
	bool quit;
} wp_event;

void wp_init(void);

wp_display* wp_create(int w, int h, int bpp, char* title);
int wp_apply(wp_display* disp);

void wp_update(wp_display* disp);
void wp_pixel(wp_display* disp, int x, int y, int r, int g, int b, int a);
void wp_track(wp_event* ev);

void wp_quit(wp_display* disp, int err);
#endif