#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat var1 = imread ("images.jpg",1);
	Mat var2(var1.rows * 2, var1.cols * 2, CV_8UC3, Scalar(0, 0, 0));
	int m, n;
	m = 0;
	for (int i = 0; i < var2.rows; i = i + 2){
		n = 0;
		for (int j = 0; j < var2.cols; j = j + 2)
		{
			var2.at<Vec3b>(i, j) = var1.at<Vec3b>(m, n);
			var2.at<Vec3b>(i, j + 1) = var1.at<Vec3b>(m, n);
			var2.at<Vec3b>(i + 1, j) = var1.at<Vec3b>(m, n);
			var2.at<Vec3b>(i + 1, j+1) = var1.at<Vec3b>(m, n);

			n++;
		}
		m++;
	}
	namedWindow("windows1", 1);
	imshow("windows1", var1);
	namedWindow("windows2", 1);
	imshow("windows2", var2);
	waitKey(0);
	return(0);
}
