cmake_minimum_required(VERSION 3.13)
project(fdf C)      # project name

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror) # flags
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
include_directories(./libft/libft)  #directory with headers
add_library(libmlx STATIC IMPORTED)
set_property(TARGET libmlx PROPERTY
        IMPORTED_LOCATION /Users/aleksandr/Documents/21/fdf2/libmlx.a)
FILE(GLOB LIBFT_SRCS ./libft/libft/*.c)  # ADD LIBFT as sources

#FILE(GLOB LIBFT_SRCS ./libftT/*.c)  # ADD LIBFT as sources

add_executable(fdf ${LIBFT_SRCS} main.c fdf.h mlx.h map.c inits.c mod.c lines.c keys.c color.c zoom.c) # all project-c-files here

target_link_libraries(fdf ${OPEN_GL} ${APP_KIT})  # LINK libraries
target_link_libraries(fdf libmlx)

target_link_libraries(fdf /Users/aleksandr/Documents/21/fdf2/libmlx.a)
#${LIBFT}