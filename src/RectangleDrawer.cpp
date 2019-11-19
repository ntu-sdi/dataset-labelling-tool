//
// Created by 22ru on 11/14/19.
//
#include "../include/RectangleDrawer.h"
#include "../include/exceptions.h"

/*
 * It doesn't seem like there is a documented
 * OpenCV testing framework available. Therefore,
 * the only way to test is manually ensuring the draw
 * functions do their job properly.
 */

cv::Mat RectangleDrawer::drawRectangle(const std::string& fileName,
                                       int x1, int y1, int x2, int y2)
{
    cv::Mat image = cv::imread(fileName, cv::IMREAD_COLOR);
    if (image.empty()) throw FileNotFoundError();
    cv::Point p1(x1, y1);
    cv::Point p2(x2, y2);

    cv::rectangle(image, p1, p2, cv::Scalar(0, 0, 255), 3);
    return image;
}

cv::Mat RectangleDrawer::drawRectangle(cv::Mat image,
                                       int x1, int y1, int x2, int y2)
{
    cv::Point p1(x1, y1);
    cv::Point p2(x2, y2);

    cv::rectangle(image, p1, p2, cv::Scalar(0, 0, 255), 3);
    return image;
}
