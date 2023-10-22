#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // ���ز�ɫͼ��
    Mat image = imread("Lena.jpg");
    if (image.empty())
    {
        std::cout << "�޷���ȡͼ���ļ�" << std::endl;
        return -1;
    }

    // ת��Ϊ�Ҷ�ͼ��
    Mat grayscale;
    cvtColor(image, grayscale, COLOR_BGR2GRAY);

    // �������ͼ��
    Mat result = grayscale.clone();

    // ��������ͼ���ƽ���Ҷ�ֵ��Ϊ��ֵ
    Scalar mean_value = mean(grayscale);

    // ���ϰ벿��ת��Ϊ��ֵͼ��
    rectangle(result, Rect(0, 0, grayscale.cols, grayscale.rows / 2), mean_value[0], -1);

    // ��ʾ���ս��
    imshow("Result", result);
    waitKey(0);

    return 0;
}