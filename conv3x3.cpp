#include <opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>


int main( int argc, char** argv ) {

    //Carregar imagem de entrada
    cv::Mat img = cv::imread("sample.png" , CV_LOAD_IMAGE_COLOR);
    cv::cvtColor( img, img, cv::COLOR_BGR2GRAY );

    //Criando o Kernel 3x3 de 1/9 para boxblur
    cv::Mat kernel = (cv::Mat_<float>(3, 3, CV_32F) <<  1, 1, 1,
                                                        1, 1, 1,
                                                        1, 1, 1) / (float)9;


    //Aplica a convolução sobre a imagem
    cv::filter2D(img, img, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    //Salva a imagem de saída
    cv::imwrite( "boxblur.jpg", img );

    // Exibir imagem de saída em janela
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", img );
    cv::waitKey(0);


    return 0;
}
