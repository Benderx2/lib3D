// SDL Wrapper for the engine
#include "wrapper.h"

void wp_init(void) {
	SDL_Init(SDL_INIT_EVERYTHING);
}
wp_display* wp_create(int w, int h, int bpp, char* title) {
	wp_display* disp = calloc(sizeof(wp_display), 1);
	disp->h = h;
	disp->w = w;
	disp->bpp = bpp;
	disp->title = title;
	return disp;
}

int wp_apply(wp_display* disp) {
	disp->buffer = NULL;
	disp->buffer = SDL_SetVideoMode(disp->w, disp->h, disp->bpp, SDL_SWSURFACE);
	if(disp->buffer == NULL) {
		return 1;
	}
	SDL_WM_SetCaption(disp->title, NULL);
	return 0;
}

void wp_update(wp_display* disp) {
	SDL_Flip(disp->buffer);
}

void wp_clear(wp_display* disp, int r, int g, int b, int a) {
	SDL_FillRect(disp->buffer, NULL, SDL_MapRGBA(disp->buffer->format, r, g, b, a));
}
void wp_quit(wp_display* disp, int code) {
	SDL_FreeSurface(disp->buffer);
	free(disp);
	SDL_Quit();
	exit(code);
}
void wp_pixel(wp_display* disp, int x, int y, int r, int g, int b, int a) {
	SDL_LockSurface(disp->buffer);
	uint32_t* pixels = (uint32_t*)disp->buffer->pixels;
	int pixoff = (disp->buffer->pitch / sizeof(uint32_t))*y + x;
	*(uint32_t*)((uintptr_t)pixels + pixoff*sizeof(uint32_t)) = SDL_MapRGBA(disp->buffer->format, r,g,b,a);
	SDL_UnlockSurface(disp->buffer);
	return;
}
void wp_track(wp_event* ev) {
	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		if(e.type == SDL_QUIT) {
			ev->quit = true;
		} else {
			ev->quit = false;
		}
	}
	ev->count = SDL_GetTicks();
}
