#include "color.h"
#include "vec3.h"

#include <iostream>

int main(){
    //Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    auto viewport_height = 2.0;
    //we dont use apsect ratio as hieght can be rounded to 1 and apsect ratio be different
    auto viewport_width = viewport_height * (double(image_width) / image_height);

    // Render
    //top of image for ppm settings
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for(int j = 0; j < image_height; j++){
        std::clog << "\rScanlines remaining" << (image_height - j) << ' ' <<  std::flush;
        for(int i = 0; i < image_width; i++){
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }
    //rewrite current line to done
    std::clog << "\rDone.               \n";
}