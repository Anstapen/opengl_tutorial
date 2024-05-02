include(FetchContent)
# get GLFW using the FetchContent Module
function(setup_glfw)
    FETCHCONTENT_DECLARE(
            glfw
            GIT_REPOSITORY https://github.com/glfw/glfw.git
            GIT_TAG 3.4
    )
    FETCHCONTENT_MAKEAVAILABLE(glfw)

endfunction()


function(setup_plog)
    FETCHCONTENT_DECLARE(
            plog
            GIT_REPOSITORY https://github.com/SergiusTheBest/plog.git
            GIT_TAG 1.1.10
    )

    FETCHCONTENT_MAKEAVAILABLE(plog)

endfunction()