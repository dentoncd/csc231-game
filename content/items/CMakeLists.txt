add_library(items
  bite.cpp
        sword.cpp
        spear.cpp
        spiked_club.cpp
        potion_red.cpp
        fire_staff.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
