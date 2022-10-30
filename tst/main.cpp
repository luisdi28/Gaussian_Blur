#include <opencv4/opencv2/opencv.hpp>
#include "gtest/gtest.h"
#include <iostream>

using namespace cv;
using namespace std;

class Server{

public:

    int método() {
        // Lee la ruta de la imagen
        Mat image = imread("/home/luis/CLionProjects/Proyecto 1 - Datos II/Gaussian_Blur/tst/cuadras.jpg");

        // Chequea si hay fallos
        if (image.empty()) {
            cout << "Could not open or find the image" << endl;
            cin.get(); // Espera para que alguna tecla sea presionada
            return -1;
        }

        //Hace la imagen con borrosa con el nucleo de Gaussian 3x3
        Mat image_blurred_with_3x3_kernel;
        GaussianBlur(image, image_blurred_with_3x3_kernel, Size(3, 3), 0);

        //Hace la imagen con borrosa con el nucleo de Gaussian 5x5
        Mat image_blurred_with_5x5_kernel;
        GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

        // Define el nombre de las ventanas emergentes
        String window_name = "Original";
        String window_name_blurred_with_3x3_kernel = "Lotus Blurred with 3 x 3 Gaussian Kernel";
        String window_name_blurred_with_5x5_kernel = "Lotus Blurred with 5 x 5 Gaussian Kernel";

        // Crea ventanas con los nombres de arriba
        namedWindow(window_name);
        namedWindow(window_name_blurred_with_3x3_kernel);
        namedWindow(window_name_blurred_with_5x5_kernel);

        // Muestra las imagenes dentro de las ventanas creadas
        imshow(window_name, image);
        imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
        imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

        waitKey(0); // Espera por alguna pulsación de teclas en la ventana

        destroyAllWindows(); // Destruye todas las ventanas creadas

        return 0;
    }
};

//Creación de la prueba unitaria
TEST(SeverTEST, Test1){
    Server servidor;

    EXPECT_EQ(servidor.método(), 0);
}

//Método que corre dicha prueba unitaria
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}