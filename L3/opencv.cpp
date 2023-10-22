#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // 加载彩色图像
    Mat image = imread("Lena.jpg");
    if (image.empty())
    {
        std::cout << "无法读取图像文件" << std::endl;
        return -1;
    }

    // 转换为灰度图像
    Mat grayscale;
    cvtColor(image, grayscale, COLOR_BGR2GRAY);

    // 创建输出图像
    Mat result = grayscale.clone();

    // 计算整个图像的平均灰度值作为阈值
    Scalar mean_value = mean(grayscale);

    // 将上半部分转化为二值图像
    rectangle(result, Rect(0, 0, grayscale.cols, grayscale.rows / 2), mean_value[0], -1);

    // 显示最终结果
    imshow("Result", result);
    waitKey(0);

    return 0;
}