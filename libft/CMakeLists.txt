cmake_minimum_required(VERSION 2.8)

project(libft)

aux_source_directory(libft SOURCE_LIB)

add_library(libft STATIC ${SOURCE_LIB})