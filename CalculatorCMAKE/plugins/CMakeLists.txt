set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library(sinus SHARED sinus.cpp)
#install(TARGETS sinus DESTINATION lib)
add_library(cosinus SHARED cosinus.cpp)
add_library(power SHARED power.cpp)