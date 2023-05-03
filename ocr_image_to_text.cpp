#include <iostream>
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>

const char * ReadImage(const char * file){
// Load the image
    cv::Mat image = cv::imread(file);

    // Create a Tesseract OCR object
    tesseract::TessBaseAPI ocr;
    ocr.Init(NULL, "eng", tesseract::OEM_DEFAULT);
    ocr.SetPageSegMode(tesseract::PSM_AUTO);

    // Convert the image to grayscale
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Set the image data for OCR
    ocr.SetImage(gray.data, gray.cols, gray.rows, 1, gray.cols);
    ocr.SetSourceResolution(172);

    // Run OCR on the image
    char* text = ocr.GetUTF8Text();

    // Print the recognized text

    // Release the memory used by the OCR object and the text
    ocr.End();
    // delete[] text; lol allocating shit....
    return text;
}

//Compile command 
int main(int argc, char ** argv) 
{
    // auto filePath = argv[1];

    if (argc > 1) {
        auto imageString = ReadImage(argv[1]); 
        std::cout<< imageString << std::endl; 
    } else {
         std::cout<<"No file path provided..."<<std::endl;
         return -1;
    }

    return 0;
}