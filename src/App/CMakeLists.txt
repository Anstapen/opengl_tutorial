add_executable(App
        main.cpp
        main.h)


target_link_libraries(App
        PRIVATE
        glfw
        glad
        plog
        )