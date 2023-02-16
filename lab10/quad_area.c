#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"

void compute_area(triangle *tri)
{
    double u[3], v[3], w[3];
    u[0] = tri->node3.x - tri->node1.x;
    u[1] = tri->node3.y - tri->node1.y;
    u[2] = 0.0;

    v[0] = tri->node2.x - tri->node1.x;
    v[1] = tri->node2.y - tri->node1.y;
    v[2] = 0.0;

    void cross_prod(double u[], double v[], double w[]);
    cross_prod(u, v, w);
    tri->area = 0.5*fabs(w[2]);
}

void cross_prod(double u[], double v[], double w[])
{
    w[0] = u[1]*v[2] - u[2]*v[1];
    w[1] = u[2]*v[0] - u[0]*v[2];
    w[2] = u[0]*v[1] - u[1]*v[0];
}