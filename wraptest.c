#include <stdio.h>
#include "raster.h"
#include "wrapper.h"

int main(int argc, char** argv) {
	wp_init();
	wp_display* display = wp_create(640, 480, 32, "Test Engine");
	wp_apply(display);
	wp_event e;
	while(true) {
		wp_track(&e);
		if(e.quit == true) {
			break;
		}
	}
	wp_quit(display, 0);
}