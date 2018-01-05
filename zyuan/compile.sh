#!/bin/bash

gcc -o mlx main.c -L ../minilibx_macos -lmlx -framework OpenGL -framework AppKit
