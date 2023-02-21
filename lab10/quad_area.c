#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrilateral.h"

void compute_area(quadrilateral *quad)
{   
    double u[3], v[3], w[3];
    quad->area = 0;

    u[0] = quad->node3.x - quad->node1.x;
    u[1] = quad->node3.y - quad->node1.y;

    v[0] = quad->node2.x - quad->node1.x;
    v[1] = quad->node2.y - quad->node1.y;

    quad->area += 0.5*fabs(u[0]*v[1] - u[1]*v[0]);

    u[0] = quad->node3.x - quad->node4.x;
    u[1] = quad->node3.y - quad->node4.y;

    v[0] = quad->node2.x - quad->node4.x;
    v[1] = quad->node2.y - quad->node4.y;

    quad->area += 0.5*fabs(u[0]*v[1] - u[1]*v[0]);

    u[0] = quad->node3.x - quad->node1.x;
    u[1] = quad->node3.y - quad->node1.y;

    v[0] = quad->node4.x - quad->node1.x;
    v[1] = quad->node4.y - quad->node1.y;

    quad->area += 0.5*fabs(u[0]*v[1] - u[1]*v[0]);

    u[0] = quad->node4.x - quad->node1.x;
    u[1] = quad->node4.y - quad->node1.y;

    v[0] = quad->node2.x - quad->node1.x;
    v[1] = quad->node2.y - quad->node1.y;

    quad->area += 0.5*fabs(u[0]*v[1] - u[1]*v[0]);

    quad->area = quad->area/2;
}

