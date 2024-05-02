cmake_minimum_required(VERSION 3.19)


project(opengl_tutorial)

# get GLFW
include(cmake/setup_dependencies.cmake)


# Multi platform library for OpenGL Application Development
# https://github.com/glfw/glfw
setup_glfw()


# Simple Logging Library
# https://github.com/SergiusTheBest/plog
setup_plog()


add_subdirectory(src)