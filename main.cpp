#include <iostream>
#include <fstream>
#include "./custom_headers/vec3.h"
#include "./custom_headers/color.h"

int main()
{
    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Image file
    std::ofstream image_file;
    image_file.open("image.ppm");

    // Render
    image_file << "P3\n"
               << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            color pixel_color(double(i) / (image_width), double(j) / (image_height), 0.25);
            write_color(image_file, pixel_color);
        }
    }
    image_file.close();
}