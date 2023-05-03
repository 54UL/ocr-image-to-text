cmake_minimum_required(VERSION 3.0)

project(ocr_image_to_text)

set(CMAKE_PREFIX_PATH "/usr/local/lib;/usr/lib;/usr/local/lib64;/usr/lib64" ${CMAKE_PREFIX_PATH})

# Find required packages
find_package(OpenCV 4 REQUIRED)
# find_package(Tesseract REQUIRED) ADD FOR WINDOWS

add_executable(ocr_image_to_text ocr_image_to_text.cpp)
target_link_libraries(ocr_image_to_text PRIVATE ${OpenCV_LIBS} tesseract)
target_compile_options(ocr_image_to_text PRIVATE ${OpenCV_CFLAGS_OTHER} ${Tesseract_CFLAGS})

# target_link_libraries(ocr_example ${OpenCV_LIBS} ${Tesseract_LIBRARIES} ${TESSERACT_LIB})