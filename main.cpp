#include "Fractals.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

void handleKeyboardInput(sf::Event event) {
    const double PAN_AMOUNT = 0.1; // Amount to pan with each key press
    const double ZOOM_IN_FACTOR = 0.9; // Zoom in factor (reduce the area)
    const double ZOOM_OUT_FACTOR = 1.1; // Zoom out factor (increase the area)

    if (event.type == sf::Event::KeyPressed) {
        // Calculate the current width and height based on current bounds
        double width = Fractal::max_real - Fractal::min_real;
        double height = Fractal::max_imag - Fractal::min_imag;

        switch (event.key.code) {
            case sf::Keyboard::W: // Zoom in
            {
                // Adjust bounds for zooming in
                double zoomWidth = width * (1 - ZOOM_IN_FACTOR);
                double zoomHeight = height * (1 - ZOOM_IN_FACTOR);
                Fractal::min_real += zoomWidth / 2;
                Fractal::max_real -= zoomWidth / 2;
                Fractal::min_imag += zoomHeight / 2;
                Fractal::max_imag -= zoomHeight / 2;

                std::cout << "Zooming In" << std::endl;
                break;
            }
            case sf::Keyboard::S: // Zoom out
            {
                // Adjust bounds for zooming out
                double zoomWidth = width * (1 - ZOOM_OUT_FACTOR);
                double zoomHeight = height * (1 - ZOOM_OUT_FACTOR);
                Fractal::min_real -= zoomWidth / 2;
                Fractal::max_real += zoomWidth / 2;
                Fractal::min_imag -= zoomHeight / 2;
                Fractal::max_imag += zoomHeight / 2;

                std::cout << "Zooming Out" << std::endl;
                break;
            }
            case sf::Keyboard::Up: // Move up
            {
                double moveAmount = PAN_AMOUNT * height;
                Fractal::min_imag += moveAmount;
                Fractal::max_imag += moveAmount;

                std::cout << "Moving Up" << std::endl;
                break;
            }
            case sf::Keyboard::Down: // Move down
            {
                double moveAmount = PAN_AMOUNT * height;
                Fractal::min_imag -= moveAmount;
                Fractal::max_imag -= moveAmount;

                std::cout << "Moving Down" << std::endl;
                break;
            }
            case sf::Keyboard::Left: // Move left
            {
                double moveAmount = PAN_AMOUNT * width;
                Fractal::min_real -= moveAmount;
                Fractal::max_real -= moveAmount;

                std::cout << "Moving Left" << std::endl;
                break;
            }
            case sf::Keyboard::Right: // Move right
            {
                double moveAmount = PAN_AMOUNT * width;
                Fractal::min_real += moveAmount;
                Fractal::max_real += moveAmount;

                std::cout << "Moving Right" << std::endl;
                break;
            }
            default:
                break; 
        }
    }
}


int main(){

    
    Fractal::Mandelbrot M;
    Fractal::Julia J;
    Fractal::Tricorn T;
    Fractal::Newtons N;
    Fractal::ComplexNewtons CN;

    // Create a window with OpenGL context
    sf::RenderWindow window(sf::VideoMode(Fractal::WIDTH, Fractal::HEIGHT), "Fratcal Grapher", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // Initialize OpenGL settings
    glClearColor(0, 0, 0, 1); // Set clear color to black
    glPointSize(1.0f); // Set point size

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle keyboard input for zooming and panning
            handleKeyboardInput(event);
        }
            glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
            window.clear();
            //M.Draw();
            //J.Draw();
            //T.Draw();
            N.Draw();
            //CN.Draw();
            window.display();
        }

        return 0;
    }
    
