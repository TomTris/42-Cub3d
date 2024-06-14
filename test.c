#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <unistd.h>
#include "cube3d.h"

int main(void) {
    // Initialize MLX
    mlx_t *mlx = mlx_init(800, 600, "Cursor Example", false);
    if (!mlx) {
        fprintf(stderr, "Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }

    // Load the cursor image
    mlx_texture_t *cursor_img = mlx_load_png("textures/cursor.png");
    if (!cursor_img) {
        fprintf(stderr, "Failed to load cursor image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

	mlx_win_cursor_t *t =  mlx_create_cursor(cursor_img);
    // Set the custom cursor
    mlx_set_cursor(mlx, t);
	mlx_set_mouse_pos(mlx, 400, 300);
	write(1, "Ads", 3);
    // Main loop

        mlx_loop(mlx);

    // Clean up
        mlx_terminate(mlx);

    return EXIT_SUCCESS;
}
