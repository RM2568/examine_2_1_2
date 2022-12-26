#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main()
{
    //读取视频文件位置
    VideoCapture cap("D:/OpenCv4.1.1/packages/video/preview.mp4");
    Mat frame;

    //判断读取是否成功
    if (!cap.isOpened())
    {
        cout << "无法打开视频文件！" << endl;
        return -1;
    }

    //显示视频帧率
    cap>>frame;
    double frame_rate=cap.get(CAP_PROP_FPS);
    cout<<"视频帧数为："<<frame_rate<<endl;

    //显示输出视频
    namedWindow("video", WINDOW_AUTOSIZE);
    while (cap.read(frame))
    {
        imshow("video", frame);
        waitKey(10);
    }
    cap.release();

    waitKey(0);
    return 0;
}

