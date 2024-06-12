#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void move_point_within_bounds(int Ax, int Ay, int Bx, int By, int *Bx_new, int *By_new, int min_bound, int max_bound) {
    // Calculate the direction vector (dx, dy)
    int dx = Bx - Ax;
    int dy = By - Ay;

    // Calculate the range for t to keep Bx_new within [min_bound, max_bound]
    double t_min_x = (min_bound - Ax) / (double)dx;
    double t_max_x = (max_bound - Ax) / (double)dx;

    // Calculate the range for t to keep By_new within [min_bound, max_bound]
    double t_min_y = (min_bound - Ay) / (double)dy;
    double t_max_y = (max_bound - Ay) / (double)dy;

    // Determine the intersection of the ranges
    double t_min = fmax(t_min_x, t_min_y);
    double t_max = fmin(t_max_x, t_max_y);

    // Check if t_min is less than or equal to t_max
    if (t_min > t_max) {
        printf("No valid t exists that keeps the coordinates within bounds.\n");
        return;
    }

    // Choose t within the valid range [t_min, t_max]
    double t = t_min; // Using the midpoint of the valid range for this example

    // Calculate the new coordinates for B
    *Bx_new = (int)round(Ax + t * dx);
    *By_new = (int)round(Ay + t * dy);

    // Ensure the coordinates are within the bounds
    if (*Bx_new < min_bound) *Bx_new = min_bound;
    if (*Bx_new > max_bound) *Bx_new = max_bound;
    if (*By_new < min_bound) *By_new = min_bound;
    if (*By_new > max_bound) *By_new = max_bound;
}

int main() {
    int Ax = 50, Ay = 50;
    int Bx = 300, By = 400;
    int Bx_new, By_new;
    int min_bound = 0, max_bound = 287;

    move_point_within_bounds(Ax, Ay, Bx, By, &Bx_new, &By_new, min_bound, max_bound);

    printf("New coordinates of point B: (%d, %d)\n", Bx_new, By_new);

    return 0;
}

// #include <string.h>

// int main()
// {
//     char *old = "111111111111000";
//     printf("%lu\n", strlen(old));
//     printf("%lu\n", sizeof(old));
//     write(2, "123132", sizeof("123132"))
// }