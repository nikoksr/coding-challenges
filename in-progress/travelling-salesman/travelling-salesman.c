/************************************************************
 * travelling salesman problem                              *
 *                                                          *
 * -> given an array of coordinates, calculate the          *
 *      shortest path possible                              *
 * -> two reallife examples are route planning and logistic *
 ************************************************************/

/* includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* declarations */
float VectorDistance(float *, float *);
float *ShortestPath(float *, int);

/* main / wrapper function */
int main()
{
    float vector_one[] = {0.0, 1.0};
    float vector_two[] = {2.0, 3.0};

    printf("\n");

    return 0;
}

/* definitions */
/* calculate the distance between two vectors */
float VectorDistance(float *vector_one, float *vector_two)
{
    float left = (vector_one[0] - vector_two[0]);
    float right = (vector_one[1] - vector_two[1]);

    left = pow(left, 2);
    right = pow(right, 2);

    float distance = fabs(sqrt(left + right));
    return distance;
}

/* calculate the shortest path in an array of coordinates / vectors */
float *ShortestPath(float *vector_array, int array_length)
{
    float *shortest_path = (float *)malloc(array_length * sizeof(float));
    float shortest_distance = 0.0;
    float current_distance = 0.0;

    return 0;
}
