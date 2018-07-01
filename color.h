#pragma once
#ifndef _COLOR_H_
#define _COLOR_H_

template <class T>
class Color {
public:
	Color();
	Color(T redComponent, T greenComponent, T blueComponent);
	Color(T redComponent, T greenComponent, T blueComponent, T alphaComponent);
	Color(const Color &input);
	~Color(void);
	Color& operator=(const Color &input);
	T getR(void);
	T getG(void);
	T getB(void);
	T getA(void);
	void setR(T redComponent);
	void setG(T greenComponent);
	void setB(T blueComponent);
	void setA(T alphaComponent);
	void setColor(T redComponent, T greenComponent, T blueComponent);
	void setColor(T redComponent, T greenComponent, T blueComponent, T alphaComponent);
private:
	T r;
	T g;
	T b;
	T a;
};

template <class T>
Color<T>::Color(void)
{
	r = 0;
	g = 0;
	b = 0;
	a = 1;
}

template <class T>
Color<T>::Color(T redComponent, T greenComponent, T blueComponent)
{
	r = redComponent;
	g = greenComponent;
	b = blueComponent;
}

template <class T>
Color<T>::Color(T redComponent, T greenComponent, T blueComponent, T alphaComponent)
{
	r = redComponent;
	g = greenComponent;
	b = blueComponent;
	a = alphaComponent;
}

template <class T>
Color<T>::Color(const Color &input)
{
	r = input.r;
	g = input.g;
	b = input.b;
	a = input.a;
}

template <class T>
Color<T>::~Color(void)
{

}

template <class T>
Color<T>& Color<T>::operator=(const Color &input)
{
	r = input.r;
	g = input.g;
	b = input.b;
	a = input.a;

	return *this;
}

template <class T>
T Color<T>::getR(void)
{
	return r;
}

template <class T>
T Color<T>::getG(void)
{
	return g;
}

template <class T>
T Color<T>::getB(void)
{
	return b;
}

template <class T>
T Color<T>::getA(void)
{
	return a;
}

template <class T>
void Color<T>::setR(T redComponent)
{
	r = redComponent;
}

template <class T>
void Color<T>::setG(T greenComponent)
{
	g = greenComponent;
}

template <class T>
void Color<T>::setB(T blueComponent)
{
	b = blueComponent;
}

template <class T>
void Color<T>::setA(T alphaComponent)
{
	a = alphaComponent;
}

template <class T>
void Color<T>::setColor(T redComponent, T greenComponent, T blueComponent)
{
	r = redComponent;
	g = greenComponent;
	b = blueComponent;
}

template <class T>
void Color<T>::setColor(T redComponent, T greenComponent, T blueComponent, T alphaComponent)
{
	r = redComponent;
	g = greenComponent;
	b = blueComponent;
	a = alphaComponent;
}

#endif // !_COLOR_H_
