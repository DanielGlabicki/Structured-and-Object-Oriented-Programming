//
// Created by Daniel on 25/04/2023.
//

#ifndef COMPLEX_1_COMPLEX_HPP
#define COMPLEX_1_COMPLEX_HPP

class Complex {
private:
    double re_;
    double im_;
public:
    Complex(double re, double im) :
    re_(re), im_(im) {}
    Complex(double data[2]) :
            Complex(data[0], data[1]) {}

    double re() const { return re_; }
    double im() const { return im_; }
};

#endif //COMPLEX_1_COMPLEX_HPP
