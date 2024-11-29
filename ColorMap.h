#include <SFML/Graphics.hpp> 
#include "InitialParameters.h" 
namespace Fractal {

    /** 
     * Function that returns the color based on the number of iterations.
     * Uses complementary-based coloring and converts the color to RGB.
     */
    sf::Color getColor(unsigned iterations);

    /**
     * Function that returns a monochromatic pink color based on the number of iterations.
     */
    sf::Color getColorPinkMonochromatic(unsigned iterations);

    /**
     * Function that returns a blue color based on the number of iterations.
     * Creates a gradient from black to blue with higher iterations turning more blue.
     */
    sf::Color getColorBlue(unsigned iterations);

}
