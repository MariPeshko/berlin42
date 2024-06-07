# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h> //Macros releated to the event names/masks, e.g. KeyPress
# include <X11/keysym.h>

// Chat GPT


typedef struct s_mlx_data {
    void *mlx_ptr;
    void *window_pointer;
} t_mlx_data;

// The callback function for handling key events
int handle_input(int keycode, t_mlx_data *data) {
    // Handle the key event here
    // Example: If the escape key is pressed, exit the program
    if (keycode == 65307) { // 65307 is the keycode for the escape key in X11
        mlx_destroy_window(data->mlx_ptr, data->window_pointer);
        exit(0);
    }
    return 0;
}

int main() {
    t_mlx_data data;

    // Initialize MiniLibX
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL) {
        return 1; // Initialization failed
    }

    // Create a new window
    data.window_pointer = mlx_new_window(data.mlx_ptr, 800, 600, "My Window");
    if (data.window_pointer == NULL) {
        return 1; // Window creation failed
    }

    // Set the key event handler
    mlx_key_hook(data.window_pointer, handle_input, &data);

    // Start the event loop
    mlx_loop(data.mlx_ptr);

    return 0;
}
