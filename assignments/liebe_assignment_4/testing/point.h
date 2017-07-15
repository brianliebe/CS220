#ifndef _POINT_H
#define _POINT_H


struct Point{
	float x; /* x, y, and z float pointers for the location. */
	float y;
	float z;
	struct Point *next;
};

int contains_loop (struct Point *points);

struct Point* transform_points(struct Point *points, struct Point *origin);



#endif