#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrilateral.h"

void compute_perimeter(quadrilateral *quad)
{   
    double V21[2], V31[2], V41[2], V32[2], V42[2], V43[2];
    V31[0] = quad->node3.x - quad->node1.x;
    V31[1] = quad->node3.y - quad->node1.y;

    V21[0] = quad->node2.x - quad->node1.x;
    V21[1] = quad->node2.y - quad->node1.y;

    V32[0] = quad->node3.x - quad->node2.x;
    V32[1] = quad->node3.y - quad->node2.y;

    V41[0] = quad->node4.x - quad->node1.x;
    V41[1] = quad->node4.y - quad->node1.y;

    V42[0] = quad->node4.x - quad->node2.x;
    V42[1] = quad->node4.y - quad->node2.y;
    
    V43[0] = quad->node4.x - quad->node3.x;
    V43[1] = quad->node4.y - quad->node3.y;

    quad->perimeter = 0.0;
    quad->perimeter += pow(V31[0]*V31[0] + V31[1]*V31[1], 0.5);
    quad->perimeter += pow(V31[0]*V31[0] + V31[1]*V31[1], 0.5);
    quad->perimeter += pow(V32[0]*V32[0] + V32[1]*V32[1], 0.5);
    quad->perimeter += pow(V32[0]*V32[0] + V32[1]*V32[1], 0.5);

    if ((V21[1]*V31[0] - V21[0]*V31[1]) * (V21[1]*V41[0] - V21[0]*V41[1]) < 0)
    {
        quad->perimeter = pow(V31[0]*V31[0] + V31[1]*V31[1], 0.5)
                        + pow(V32[0]*V32[0] + V32[1]*V32[1], 0.5)
                        + pow(V41[0]*V41[0] + V41[1]*V41[1], 0.5)
                        + pow(V42[0]*V42[0] + V42[1]*V42[1], 0.5);
    }
    else
    {
        if ((V31[1]*V41[0] - V31[0]*V41[1]) * (V31[1]*V21[0] - V31[0]*V21[1]) < 0)
        {
            quad->perimeter = pow(V21[0]*V21[0] + V21[1]*V21[1], 0.5)
                + pow(V32[0]*V32[0] + V32[1]*V32[1], 0.5)
                + pow(V41[0]*V41[0] + V41[1]*V41[1], 0.5)
                + pow(V43[0]*V43[0] + V43[1]*V43[1], 0.5);
        }
        else
        {
            quad->perimeter = pow(V21[0]*V21[0] + V21[1]*V21[1], 0.5)
                + pow(V31[0]*V31[0] + V31[1]*V31[1], 0.5)
                + pow(V42[0]*V42[0] + V42[1]*V42[1], 0.5)
                + pow(V43[0]*V43[0] + V43[1]*V43[1], 0.5);
        }
    }
}