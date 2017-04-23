class Complex {
public:

	Complex(double re, double im);
	Complex();

	~Complex();

	Complex conjugate();
	double getRe();
	double getIm();

private:

	double re;
	double im;
};
