file(GLOB PDCURSES_SRC ./pdcurses/*.c)
file(GLOB WINCON_SRC ./wincon/*.c)

add_library(PDCurses STATIC ${PDCURSES_SRC} ${WINCON_SRC})
target_include_directories(PDCurses PUBLIC . PRIVATE pdcurses wincon common)