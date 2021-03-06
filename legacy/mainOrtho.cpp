/* main.cpp - The main of the program. Used to put things in place
 * Quang Tran - 9/12/2019
 * */

#include "baseclass/baseclass_headers.hpp"
#include <vector>

//defining canvas size in pixels
const int CANVAS_X = 500;
const int CANVAS_Y = 500;
//defining world's dimension
const float WORLD_X = 5;
const float WORLD_Y = 5;

//translated directly from slide's pseudocode
//and the book's hints
int main(int argc, char** argv) {
    //handling inputs
    std::vector<double> a;
    for (int i = 1; i < argc; i++) {
        a.push_back(atof(argv[i]));
    }
    
    //making a canvas
    Canvas canvas(CANVAS_X, CANVAS_Y);
    //define red
    Color red(1, 0, 0);
    //define white
    Color white(1, 1, 1);
    //make a sphere
    Sphere sphere;
    //setting a material
    Material m;
    m.setColor(red);
    m.setAmbient(0.2);
    m.setDiffuse(1.0);
    m.setShininess(0.0);
    sphere.setMaterial(m);

    //light
    PointLight light(Tuple::Point(-2, 2, -5), white);

    double x, y;
    for (double j = 0; j < CANVAS_Y; j++) {
        //iterating over vertical pixels
        //calculating world y
        y = (WORLD_Y / 2) - j / (CANVAS_Y / WORLD_Y);
        for (double i = 0; i < CANVAS_X; i++) {
            //Catching intersections
            //calculating world x
            x = -(WORLD_X / 2) + i / (CANVAS_X / WORLD_X);
            Tuple origin = Tuple::Point(x, y, -5);
            Tuple direction = Tuple::Vector(0, 0, 1);
            Ray ray(origin, direction);
            std::vector<double> ints = sphere.intersect(ray);

            //Checking hits
            for (size_t t = 0; t < ints.size(); t++) {
                if (ints[t] > 0) {
                    Tuple hitPoint = ray.position(ints[t]);
                    Color trueColor = lighting(sphere.getMaterial(),
                                               light,
                                               hitPoint,
                                               sphere.normalAt(hitPoint),
                                               ray.getOrigin());
                    canvas.write_pixel(i, j, trueColor);
                    break;
                }
            }
        }
    }
    canvas.toPPM("out0.ppm");

    return 0;
}
