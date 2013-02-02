//
//  vector_display.h
//  Vector
//
//  Created by Brian Luczkiewicz on 11/22/12.
//  Copyright (c) 2012 Brian Luczkiewicz. All rights reserved.
//

#ifndef Vector_vector_display_h
#define Vector_vector_display_h

typedef struct vector_display vector_display_t;

typedef void (*vector_display_log_cb_t)(const char *msg);

// create a new vector display
int vector_display_new(vector_display_t **out_self, double width, double height);

// resize a vector display
int vector_display_resize(vector_display_t *self, double width, double height);

// delete a vector display
void vector_display_delete(vector_display_t *self);

// update the screen. make sure that the screen's FBO is bound
int vector_display_update(vector_display_t *self);

// setup opengl, assumes context is already set
int vector_display_setup(vector_display_t *self);

// tear down opengl, assumes context is already set
int vector_display_teardown(vector_display_t *self);

// clear display
int vector_display_clear(vector_display_t *self);

// add a vector to the display list; x/y are from [0,1)
int vector_display_draw(vector_display_t *self, double x0, double y0, double x1, double y1);

// draw connected lines
int vector_display_begin_draw(vector_display_t *self, double x, double y);
int vector_display_draw_to(vector_display_t *self, double x, double y);
int vector_display_end_draw(vector_display_t *self);

// set the drawing color
int vector_display_set_color(vector_display_t *self, double r, double g, double b);

// set number of fade steps
int vector_display_set_steps(vector_display_t *self, int steps);

// set decay per step
int vector_display_set_decay(vector_display_t *self, double decay);

// set decay on first step
int vector_display_set_initial_decay(vector_display_t *self, double initial_decay);

// set thickness
int vector_display_set_thickness(vector_display_t *self, double thickness);

// get size previous set on vector display
void vector_display_get_size(vector_display_t *self, double *out_width, double *out_height);

// install a logging callback
void vector_display_set_log_cb(vector_display_log_cb_t cb_log);

#endif
