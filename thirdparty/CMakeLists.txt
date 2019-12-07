file(GLOB PDCURSES_SRC ./pdcurses/*.cpp)
file(GLOB WINCON_SRC ./wincon/*.cpp)

add_library(PDCurses STATIC ${PDCURSES_SRC} ${WINCON_SRC})
target_include_directories(PDCurses PUBLIC . PRIVATE pdcurses wincon common)