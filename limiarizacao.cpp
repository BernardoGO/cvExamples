#include <opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
 
int main( int argc, char** argv ) {

    //Carregar imagem de entrada
    cv::Mat img = cv::imread("sample.png" , CV_LOAD_IMAGE_COLOR);
    
    // Converte imagem para tons de 
    cv::cvtColor( img, img, cv::COLOR_BGR2GRAY );

    // Limiarização binária de 64 para 255.
    cv::threshold(img,img, 64, 255, cv::THRESH_BINARY);

    //Salva a imagem de saída
    cv::imwrite( "output.jpg", img );

    // Exibir imagem de saída em janela
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", img );
    cv::waitKey(0);


    return 0;
}
