#include "ColorMap.h"

namespace Fractal{

    
    sf::Color getColor(unsigned iterations) {
        if(iterations == Fractal::MAX_ITERATIONS){
            return sf::Color(0,0,0);// BLACK TO REPRESENT POINT IN THE SET
        }
        else{
            
        // Normalize the iterations
        float t = static_cast<float>(iterations) / static_cast<float>(Fractal::MAX_ITERATIONS);

        
        // Spectral color mapping (using wavelengths for RGB)
        float wavelength = 400.0f + (300.0f * t); // Map normalized iterations to wavelengths (400-700 nm)

        // Initialize RGB values
        float r = 0.0f, g = 0.0f, b = 0.0f;

        // Determine RGB values based on wavelength
        if (wavelength >= 400.0 && wavelength < 410.0) {
            r = 0.33 * (wavelength - 400.0) / (410.0 - 400.0);
            g = 0.0f;
            b = 1.0f; // Blue
        } else if (wavelength >= 410.0 && wavelength < 475.0) {
            r = 0.14 - 0.13 * (wavelength - 410.0) / (475.0 - 410.0);
            g = 0.80 * (wavelength - 410.0) / (475.0 - 410.0); // Green increases
            b = 1.0f; // Blue
        } else if (wavelength >= 475.0 && wavelength < 590.0) {
            r = 0.0f; // Red stays off
            g = 0.8f + 0.76 * (wavelength - 475.0) / (590.0 - 475.0); // Green increases
            b = 1.0f - (wavelength - 475.0) / (590.0 - 475.0); // Blue decreases
        } else if (wavelength >= 590.0 && wavelength < 650.0) {
            r = 1.98 * (wavelength - 590.0) / (650.0 - 590.0); // Red increases
            g = 0.98 - 0.06 * (wavelength - 590.0) / (650.0 - 590.0); // Green decreases
            b = 0.0f; // Blue stays off
        } else if (wavelength >= 650.0 && wavelength < 700.0) {
            r = 0.65 - 0.84 * (wavelength - 650.0) / (700.0 - 650.0); // Red decreases
            g = 0.0f; // Green stays off
            b = 0.0f; // Blue stays off
        }

        // Convert to sf::Color
        return sf::Color(static_cast<sf::Uint8>(r * 255), static_cast<sf::Uint8>(g * 255), static_cast<sf::Uint8>(b * 255));
        
        }
    };

    sf::Color getColorPinkMonochromatic(unsigned iterations) {
        if(iterations == Fractal::MAX_ITERATIONS){
            return sf::Color(0,0,0);// BLACK TO REPRESENT POINT IN THE SET
        }
        else{
            
        // Normalize the iterations
        float t = static_cast<float>(iterations) / static_cast<float>(Fractal::MAX_ITERATIONS);

        // Define colors for the gradient
        float r = static_cast<sf::Uint8>(255 * t); // Red increases
        float g = 0;
        float b = static_cast<sf::Uint8>(192 * t); // Blue increases to create pink

        return sf::Color(r, g, b);

        }


    };

    sf::Color getColorBlue(unsigned iterations){
        if(iterations == Fractal::MAX_ITERATIONS){
            return sf::Color(0,0,0);// BLACK TO REPRESENT POINT IN THE SET
        }
        else{
            
        // Normalize the iterations
        float t = static_cast<float>(iterations) / static_cast<float>(Fractal::MAX_ITERATIONS);

        float r,g,b;

        // Create a gradient effect
        r = static_cast<sf::Uint8>(0); // Red stays minimal for blue shades
        g = static_cast<sf::Uint8>(0); // Green stays minimal for blue shades
        b = static_cast<sf::Uint8>(255 * t); // Blue increases with iterations

        // Further manipulation for gradient effects
        if (t < 0.5) {
            b = static_cast<sf::Uint8>(255 * t * 2); // Enhance blue for low iterations
        } else {
            // Add some white for higher iterations
            r = static_cast<sf::Uint8>(255 * (t - 0.5) * 2); // Increase red slightly
            g = static_cast<sf::Uint8>(255 * (t - 0.5) * 2); // Increase green slightly
            b = static_cast<sf::Uint8>(255 * (1 - t)); // Reduce blue as iterations increase
        }

        return sf::Color(r, g, b);

        }
    };

}






    