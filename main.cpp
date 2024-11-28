#include <iostream>

int main(){
    //Image
    int image_width = 256;
    int image_height = 256;

    // Render
    //top of image for ppm settings
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for(int j = 0; j < image_height; j++){
        std::clog << "\rScanlines remaining" << (image_height - j) << ' ' <<  std::flush;
        for(int i = 0; i < image_width; i++){
            //define rgb value from 0-255 / 255 (0-1) for each pixel between vertexes
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}