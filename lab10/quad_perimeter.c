#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"

void compute_perimeter(triangle *tri)
{   
    double u[2], v[2], w[2];
    u[0] = tri->node3.x - tri->node1.x;
    u[1] = tri->node3.y - tri->node1.y;

    v[0] = tri->node2.x - tri->node1.x;
    v[1] = tri->node2.y - tri->node1.y;

    w[0] = tri->node3.x - tri->node2.x;
    w[1] = tri->node3.y - tri->node2.y;

    tri->perimeter = 0.0;
    tri->perimeter += pow(u[0]*u[0] + u[1]*u[1], 0.5);
    tri->perimeter += pow(v[0]*v[0] + v[1]*v[1], 0.5);
    tri->perimeter += pow(w[0]*w[0] + w[1]*w[1], 0.5);
}