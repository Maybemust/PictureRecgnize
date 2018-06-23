#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/ml/ml.hpp"
#include <iostream>
#include <cstdio>
using namespace cv;

int main()
{
    // 512 x 512 零矩阵
    int width = 512, height = 512;
    Mat img = Mat::zeros(height, width, CV_8UC3);

    // 训练样本
    float train_data[6][2] = { { 500, 60 },{ 245, 40 },{ 480, 250 },{ 160, 380 },{400, 25},{55, 400} };
    float labels[6] = {0,0,0,1,0,1};  // 每个样本数据对应的输出
    Mat train_data_mat(6, 2, CV_32FC1, train_data);
    Mat labels_mat(6, 1, CV_32FC1, labels);

    // BP 模型创建和参数设置
    Ptr<ml::ANN_MLP> bp = ml::ANN_MLP::create();

    Mat layers_size = (Mat_<int>(1,3) << 2,6,1); // 2维点，1维输出
    bp->setLayerSizes(layers_size);

    bp->setTrainMethod(ml::ANN_MLP::BACKPROP,0.1,0.1);
    bp->setActivationFunction(ml::ANN_MLP::SIGMOID_SYM);
    bp->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, /*FLT_EPSILON*/1e-6));

    // 保存训练好的神经网络参数
    bool trained = bp->train(train_data_mat,ml::ROW_SAMPLE,labels_mat);
    if (trained) {
        bp->save("bp_param");
    }

    // 创建训练好的神经网络
//    Ptr<ml::ANN_MLP> bp = ml::ANN_MLP::load("bp_param");

    // 显示分类的结果
    Vec3b green(0, 255, 0), blue(255, 0, 0);
    for (int i=0; i<img.rows; ++i) {
        for (int j=0; j<img.cols; ++j) {
            Mat sample_mat = (Mat_<float>(1, 2) << j, i);
            Mat response_mat;
            bp->predict(sample_mat,response_mat);
            float response = response_mat.ptr<float>(0)[0];
            if (response > 0.5) {
                img.at<Vec3b>(i, j) = green;
            } else if (response < 0.5) {
                img.at<Vec3b>(i, j) = blue;
            }
        }
    }

    // 画出训练样本数据
    int thickness = -1;
    int lineType = 8;
    circle(img, Point(500, 60), 5, Scalar(255, 255, 255), thickness, lineType);
    circle(img, Point(245, 40), 5, Scalar(255, 255, 255), thickness, lineType);
    circle(img, Point(480, 250), 5, Scalar(255, 255, 255), thickness, lineType);
    circle(img, Point(160, 380), 5, Scalar(0, 0, 255), thickness, lineType);
    circle(img, Point(400, 25), 5, Scalar(255, 255, 255), thickness, lineType);
    circle(img, Point(55, 400), 5, Scalar(0, 0, 255), thickness, lineType);

    imwrite("result.png", img);        // 保存训练的结果
    imshow("BP Simple Example", img);

    waitKey(0);
}