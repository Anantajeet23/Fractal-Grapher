#include <complex>
#include <iostream>

namespace Fractal{
    /* the size of the window to display the fractal */
    extern const unsigned WIDTH;
    extern const unsigned HEIGHT;

    /* The maximum number of iterations we wat to do for each pixel on the screen */
    extern const unsigned MAX_ITERATIONS;

    /** The upper and lower boundaries on the complex plane.
     * Each pixel is converted to a point in the complex plane.
     * In order to ensure one to one mapping between the pixel and complex numbers we use a boundary.
     * This improves the clarity of the fractal and gives sharper details.
     * These boundaries wil be changed while the program is running based on the zoom of the display window.
    */

    extern double min_real;
    extern double max_real;
    extern double min_imag;
    extern double max_imag;


}

