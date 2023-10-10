# CMakeList.txt: проект CMake для CalculatorCMAKE; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

#link_directories("C:/Users/HP/OneDrive/Рабочий стол/myProg/CalculatorCMAKE/out/build/x64-Debug/plugins")

add_subdirectory ("plugins")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CalculatorCMAKE "main.cpp"  "Token.h" "Parser.h" "Converter.h" "Calculator.h" "Parser.cpp" "Converter.cpp" "Calculator.cpp" "Loader.h")

# target_link_libraries(CalculatorCMAKE sinus cosinus power)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
