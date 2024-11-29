#include "ColorMap.h"
#include <SFML/OpenGL.hpp>
#include <complex>

namespace Fractal {

    // Abstract base class for fractals
    class Fractals {
    public:
        virtual ~Fractals() = default;

        // Virtual function to display the fractal on the window
        virtual void Draw() = 0;

        // Virtual function to find the number of iterations for each point
        virtual int Calculate(std::complex<double> c) = 0;
    };

    // Mandelbrot set class
    class Mandelbrot : public Fractals {
    public:
        Mandelbrot();

        int Calculate(std::complex<double> c);
        void Draw();
    };

    // Julia set class
    class Julia : public Fractals {
    public:
        std::complex<double> C; // Constant value for the Julia set

        Julia();

        int Calculate(std::complex<double> z);
        void Draw();
    };

    // Tricorn set class
    class Tricorn : public Fractals {
    public:
        Tricorn();

        int Calculate(std::complex<double> c);
        void Draw();
    };

    // Newton's fractal class
    class Newtons : public Fractals {
    public:
        Newtons();

        std::complex<double> f(std::complex<double> z);
        std::complex<double> f_prime(std::complex<double> z);

        int Calculate(std::complex<double> z);
        void Draw();
    };

    // Complex Newton's fractal class
    class ComplexNewtons : public Fractals {
    public:
        std::complex<double> C; // Constant value for the fractal

        ComplexNewtons();

        std::complex<double> f(std::complex<double> z);
        std::complex<double> f_prime(std::complex<double> z);

        int Calculate(std::complex<double> z);
        void Draw();
    };

}