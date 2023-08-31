#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("input.png");

    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    
    cv::Size newSize(400, 300);
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, newSize);

    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(5, 5), 0);

    cv::imshow("Original Image", image);
    cv::imshow("Grayscale Image", grayImage);
    cv::imshow("Resized Image", resizedImage);
    cv::imshow("Blurred Image", blurredImage);

    cv::waitKey(0); 

    return 0;
}
