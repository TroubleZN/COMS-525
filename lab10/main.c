#include <stdio.h>
#include <math.h>
#include "quadrilateral.h"

int main()
{
    quadrilateral q;
    q.node1.x = 0.0;    q.node1.y = 0.0;
    q.node2.x = -0.5;   q.node2.y = 0.5;
    q.node3.x = -1.0;   q.node3.y = 2.5;
    q.node4.x = 1.0;    q.node4.y = 1.0; 
    

    printf("The info of the quadrilateral: \n");
    printf(" node1: ( %lf, %lf )\n", q.node1.x, q.node1.y);
    printf(" node2: ( %lf, %lf )\n", q.node2.x, q.node2.y);
    printf(" node3: ( %lf, %lf )\n", q.node3.x, q.node3.y);
    printf(" node4: ( %lf, %lf )\n", q.node4.x, q.node4.y);

    void compute_area(quadrilateral *quad);
    compute_area(&q);

    void compute_perimeter(quadrilateral *quad);
    compute_perimeter(&q);

    printf("\n area = %e\n", q.area);
    printf(" perimeter = %e\n", q.perimeter);

    return 0;
}