#include <complex>
#include <iostream>
#include "Fractals.h"
#include <SFML/OpenGL.hpp>

namespace Fractal{

        Mandelbrot::Mandelbrot(){}

        int Mandelbrot::Calculate(std::complex<double> c){
            std::complex<double> z(0); // The initial value for the mandelbrot set.
            int count = 0; // vraiable to hold the number of iterations we have done.

            while (std::abs(z) <= 2.0 && count < MAX_ITERATIONS) {
                z = z * z + c;
                count++;
            }
            return count;
        }

        void Mandelbrot::Draw(){
            glBegin(GL_POINTS); // Start drawing points

            for (int x = 0; x < WIDTH; x++) {
                for (int y = 0; y < HEIGHT; y++) {
                    //Convert the pixel to point in the complex plane
                    double real = min_real + (max_real - min_real) * x / WIDTH;
                    double imag = min_imag + (max_imag - min_imag) * y / HEIGHT;
                    std::complex<double> c(real, imag);

                    int iterations = Calculate(c);
                    //Finds the color of the vertex
                    sf::Color color = getColor(iterations);

                    // Set the color for this point
                    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);

                    // Map pixel coordinates to OpenGL coordinates
                    float glX = (x - WIDTH / 2.0f) / (WIDTH / 2.0f);
                    float glY = (y - HEIGHT / 2.0f) / (HEIGHT / 2.0f);

                    // Draw the point
                    glVertex2f(glX, glY);
                }
            }
           glEnd(); // End drawing points

        }



        Julia::Julia(){
            this->C = std::complex<double>(-0.70176, -0.3842);
        }

         int Julia::Calculate(std::complex<double> z){
            int count = 0; // vraiable to hold the number of iterations we have done.

            while (std::abs(z) <= 2.0 && count < MAX_ITERATIONS) {
                z = z * z + C;
                count++;
            }
            return count;
        }

        void Julia::Draw(){
            glBegin(GL_POINTS); // Start drawing points

            for (int x = 0; x < WIDTH; x++) {
                for (int y = 0; y < HEIGHT; y++) {
                    //Convert the pixel to point in the complex plane
                    double real = min_real + (max_real - min_real) * x / WIDTH;
                    double imag = min_imag + (max_imag - min_imag) * y / HEIGHT;
                    std::complex<double> z(real, imag);

                    int iterations = Calculate(z);
                    //Finds the color of the vertex
                    sf::Color color = getColorPinkMonochromatic(iterations);

                    // Set the color for this point
                    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);

                    // Map pixel coordinates to OpenGL coordinates
                    float glX = (x - WIDTH / 2.0f) / (WIDTH / 2.0f);
                    float glY = (y - HEIGHT / 2.0f) / (HEIGHT / 2.0f);

                    // Draw the point
                    glVertex2f(glX, glY);
                }
            }
           glEnd(); // End drawing points

        }



        Tricorn::Tricorn(){}

        int Tricorn::Calculate(std::complex<double> c){
            std::complex<double> z(0); // The initial value for the Tricorn set.
            int count = 0; // vraiable to hold the number of iterations we have done.

            while (std::abs(z) <= 2.0 && count < MAX_ITERATIONS) {
                z = std::conj(z) * std::conj(z) + c;
                count++;
            }
            return count;
        }

        void Tricorn::Draw(){
            glBegin(GL_POINTS); // Start drawing points

            for (int x = 0; x < WIDTH; x++) {
                for (int y = 0; y < HEIGHT; y++) {
                    //Convert the pixel to point in the complex plane
                    double real = min_real + (max_real - min_real) * x / WIDTH;
                    double imag = min_imag + (max_imag - min_imag) * y / HEIGHT;
                    std::complex<double> c(real, imag);

                    int iterations = Calculate(c);
                    //Finds the color of the vertex
                    sf::Color color = getColor(iterations);

                    // Set the color for this point
                    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);

                    // Map pixel coordinates to OpenGL coordinates
                    float glX = (x - WIDTH / 2.0f) / (WIDTH / 2.0f);
                    float glY = (y - HEIGHT / 2.0f) / (HEIGHT / 2.0f);

                    // Draw the point
                    glVertex2f(glX, glY);
                }
            }
           glEnd(); // End drawing points

        }


        Newtons::Newtons(){}

        // Function definition: f(z) = z^3 - 1
        std::complex<double> Newtons::f(std::complex<double> z) {
            return z * z * z * z  - 1.0; // z^3 - 1
        }

        // Derivative of the function: f'(z) = 3*z^2
        std::complex<double> Newtons::f_prime(std::complex<double> z) {
            return 4.0 * z * z * z  ; // 3*z^2
        }

        int Newtons::Calculate(std::complex<double> z) {
            int count = 0; // Variable to hold the number of iterations

            while (std::abs(f(z)) > 1e-6 && count < MAX_ITERATIONS) {
                z = z - f(z) / f_prime(z); // Newton's method update
                count++;
            }
        // Return the number of iterations
        return count;
        }

        void Newtons::Draw(){
            glBegin(GL_POINTS); // Start drawing points

            for (int x = 0; x < WIDTH; x++) {
                for (int y = 0; y < HEIGHT; y++) {
                    //Convert the pixel to point in the complex plane
                    double real = min_real + (max_real - min_real) * x / WIDTH;
                    double imag = min_imag + (max_imag - min_imag) * y / HEIGHT;
                    std::complex<double> c(real, imag);

                    int iterations = Calculate(c);
                    //Finds the color of the vertex
                    sf::Color color = getColor(iterations);
                  
                    
                    // Set the color for this point
                    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);

                    // Map pixel coordinates to OpenGL coordinates
                    float glX = (x - WIDTH / 2.0f) / (WIDTH / 2.0f);
                    float glY = (y - HEIGHT / 2.0f) / (HEIGHT / 2.0f);

                    // Draw the point
                    glVertex2f(glX, glY);
                }
            }
           glEnd(); // End drawing points

        }

        ComplexNewtons::ComplexNewtons(){
            this->C = std::complex<double>(0.5, 0.5); // Change this to any complex constant you like
        }

        // Function to calculate f(z) for z^4 + z^2 - c
        std::complex<double>  ComplexNewtons::f(std::complex<double> z) {
            return std::pow(z, 4) + std::pow(z, 2) - C; // z^4 + z^2 - c
        }

        // Function to calculate the derivative f'(z)
        std::complex<double>  ComplexNewtons::f_prime(std::complex<double> z) {
            return 4.0 * std::pow(z, 3) + 2.0 * z; // 4z^3 + 2z
        }


        int  ComplexNewtons::Calculate(std::complex<double> z) {
            int count = 0; // Variable to hold the number of iterations

            while (std::abs(f(z)) > 1e-6 && count < MAX_ITERATIONS) {
                z = z - f(z) / f_prime(z); // Newton's method update
                count++;
            }
        // Return the number of iterations
        return count;
        }

        void  ComplexNewtons::Draw(){
            glBegin(GL_POINTS); // Start drawing points

            for (int x = 0; x < WIDTH; x++) {
                for (int y = 0; y < HEIGHT; y++) {
                    //Convert the pixel to point in the complex plane
                    double real = min_real + (max_real - min_real) * x / WIDTH;
                    double imag = min_imag + (max_imag - min_imag) * y / HEIGHT;
                    std::complex<double> c(real, imag);

                    int iterations = Calculate(c);
                    //Finds the color of the vertex
                    sf::Color color = getColor(iterations);
                  
                    
                    // Set the color for this point
                    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);

                    // Map pixel coordinates to OpenGL coordinates
                    float glX = (x - WIDTH / 2.0f) / (WIDTH / 2.0f);
                    float glY = (y - HEIGHT / 2.0f) / (HEIGHT / 2.0f);

                    // Draw the point
                    glVertex2f(glX, glY);
                }
            }
           glEnd(); // End drawing points

        }

}




