#include <opencv2/highgui.hpp>
#include <iostream>
 
int main( int argc, char** argv ) {

    //Carregar imagem de entrada
    cv::Mat img = cv::imread("sample.jpeg" , CV_LOAD_IMAGE_COLOR);

    for (int i = 0; i < img.rows; ++i) //Loop pelas linhas da imagem
    {
        // Primeiro pixel da linha atual
        cv::Vec3b* pixel = img.ptr<cv::Vec3b>(i); 
        for (int j = 0; j < img.cols; ++j) //Loop pelas colunas da imagem
        {
            //Inverte cada um dos três (R,G,B) canais da imagem com operador `not`
            pixel[j][2] = ~pixel[j][2];
            pixel[j][1] = ~pixel[j][1];
            pixel[j][0] = ~pixel[j][0];
        }
        
    }

    //Exibir imagem de saída em janela
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", img );
    cv::waitKey(0);


    return 0;
}
