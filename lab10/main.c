#include <stdio.h>
#include <math.h>
#include "triangle.h"

int main()
{
    triangle t;
    t.node1.x = 0.0;    t.node1.y = 0.0;
    t.node2.x = -0.5;   t.node2.y = 0.5;
    t.node3.x = -1.0;   t.node3.y = 2.5;

    printf("The info of the triangle: \n");
    printf(" node1: (%lf, %lf)\n", t.node1.x, t.node1.y);
    printf(" node2: (%lf, %lf)\n", t.node2.x, t.node2.y);
    printf(" node3: (%lf, %lf)\n", t.node3.x, t.node3.y);

    void compute_area(triangle *tri);
    compute_area(&t);

    void compute_perimeter(triangle *tri);
    compute_perimeter(&t);

    printf(" area = %e\n", t.area);
    printf(" perimeter = %e\n", t.perimeter);

    return 0;
}