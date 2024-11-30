#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

color ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main(){
    //Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    //camera!!
    auto viewport_height = 2.0;
    //we dont use apsect ratio as hieght can be rounded to 1 and apsect ratio be different
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto focal_length = 1.0;
    auto camera_center = point3(0,0,0);

    //calculate vu and vv for pixel w and h from pixel to pixel
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0); //why -?

    //calculate horiz and vert delta vectors from pixel to pixel (change in pixel per pixel)
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    //find uperleft pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    //centers viewport by half pixel
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
    //top of image for ppm settings
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for(int j = 0; j < image_height; j++){
        std::clog << "\rScanlines remaining" << (image_height - j) << ' ' <<  std::flush;
        for(int i = 0; i < image_width; i++){
            auto current_pixel_center = pixel00_loc + pixel_delta_u * i + pixel_delta_v * j;
            auto ray_direction = current_pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    //rewrite current line to done
    std::clog << "\rDone.               \n";
}