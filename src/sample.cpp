#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <Eigen/LU>
#include <opencv2/opencv.hpp>

namespace py = pybind11;

void data_in(const Eigen::MatrixXd &input)
{
    int rows = input.rows();
    int cols = input.cols();

    std::cout << "rows: " << rows <<  " cols: " << cols << std::endl;
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            std::cout << input(y, x) << " ";
        }
        std::cout << std::endl;
    } 
}

Eigen::MatrixXd data_out(int rows, int cols)
{
    int size = rows * cols;
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(rows, cols);
    return m;
}

void img_in(py::array_t<uint8_t>& input) {
    py::buffer_info buf = input.request();
    cv::Mat mat(buf.shape[0], buf.shape[1], CV_8UC3, (uint8_t*)buf.ptr);
    cv::imshow("Image IN", mat);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

py::array_t<uint8_t> img_out(const char* filename)
{
    cv::Mat img = cv::imread(cv::samples::findFile(filename));
    int height = img.rows;
    int width = img.cols;
    int depth = img.channels();
    py::array_t<uint8_t> out_img = py::array_t<uint8_t>({height, width, depth}, img.data);
    return out_img;
}

PYBIND11_MODULE(sample,m)
{
    m.doc() = "pybind11 example plugin";

    m.def("data_in", &data_in);
    m.def("data_out", &data_out, py::return_value_policy::move);
    m.def("img_in", &img_in);
    m.def("img_out", &img_out, py::return_value_policy::move);
}
