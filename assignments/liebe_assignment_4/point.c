#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int contains_loop(struct Point *points) {
	
	struct Point *starter = points;
	struct Point *tempPoint = starter;
	/* starter is used so that I'll never lose the original place.
	 * tempPoint is used to cycle through and check for matching xyz's.
	 */

	
	int loop = 0; /* whether or not it's a loop. */
	int increment = 0; /* this is to know how far I've gone. */
	if (points != NULL) {

		while (points->next != NULL && loop == 0) {

			points = (struct Point *)points->next; /* increment the points to next point */
			increment++;
			int i;
			tempPoint = starter; /* start from beginning */
			for (i = 0; i < increment - 1; i++) {
				tempPoint = (struct Point *)tempPoint->next; /* moves to next Point */
				/*
				if (tempPoint->x == points->x && tempPoint->y == points->y && tempPoint->z == points->z) {
					loop = 1;
				} /* checks back thorugh the loop to make sure I haven't been here before. */
				if (tempPoint == points) {
					loop = 1;
				}
			}
		}
	}


	return loop;
}

struct Point* transform_points(struct Point *points, struct Point *origin) {

	struct Point *newPoint = (struct Point *) malloc (sizeof(struct Point));
	struct Point *oldPoint = (struct Point *)points;
	struct Point *returnPoint = (struct Point *)points;
	/* these lines create 3 points, one that moves through the old chain, and one through the new. 
	 * the last point will be the first point that newPoint becomes. 
	 */

	if (points != NULL) {
		int firstRun = 1;
		while (oldPoint->next != NULL) {
			newPoint->x = oldPoint->x + origin->x;
			newPoint->y = oldPoint->y + origin->y;
			newPoint->z = oldPoint->z + origin->z;
			/* this sets the first Point of newPoint to be the shifted first Point in the old chain. */

			struct Point *tempPoint = (struct Point *) malloc (sizeof(struct Point));
			/* create a new point for the next spot in the chain. */

			newPoint->next = tempPoint; /* move to the next spot in the chain. */
			if (firstRun == 1) { /* this just makes sure returnPoint will get set. */
				returnPoint = newPoint;
				firstRun = 0;
			}
			newPoint = tempPoint; /* newPoint takes the place of the new Point */
			oldPoint = (struct Point *) oldPoint->next; /* oldPoint moves to next chanin. */
		}

		newPoint->x = oldPoint->x + origin->x; /* sets the last point in the chain before exiting. */
		newPoint->y = oldPoint->y + origin->y;
		newPoint->z = oldPoint->z + origin->z;
		if (firstRun == 1) { /* check to make sure RP is set, if the chain is 1 point long. */
			returnPoint = newPoint;
			firstRun = 0;
		}
	}
	return returnPoint;
}
