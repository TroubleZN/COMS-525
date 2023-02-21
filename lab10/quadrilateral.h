#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

typedef struct point point;
struct point
{
    double x;
    double y;
};

typedef struct quadrilateral quadrilateral;
struct quadrilateral
{
    point node1;
    point node2;
    point node3;
    point node4;
    
    double area;
    double perimeter;
};

#endif