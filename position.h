#pragma once
#ifndef POSITION_H_
#define POSITION_H_

template <class T>
class Position {
public:
	Position();
	Position(T abscissa, T ordinate, T depth);
	Position(const Position &input);
	~Position(void);
	Position& operator=(const Position &input);
	T getX(void);
	T getY(void);
	T getZ(void);
	void setX(T abscissa);
	void setY(T ordinate);
	void setZ(T depth);
	void setPosition(T abscissa, T ordinate, T depth);
private:
	T x;
	T y;
	T z;
};

template <class T>
Position<T>::Position(void)
{
	x = 0;
	y = 0;
	z = 0;
}

template <class T>
Position<T>::Position(T abscissa, T ordinate, T depth)
{
	x = abscissa;
	y = ordinate;
	z = depth;
}

template <class T>
Position<T>::Position(const Position &input)
{
	x = input.x;
	y = input.y;
	z = input.z;
}

template <class T>
Position<T>::~Position(void)
{

}

template <class T>
Position<T>& Position<T>::operator=(const Position &input)
{
	x = input.x;
	y = input.y;
	z = input.z;

	return *this;
}

template <class T>
T Position<T>::getX(void)
{
	return x;
}

template <class T>
T Position<T>::getY(void)
{
	return y;
}

template <class T>
T Position<T>::getZ(void)
{
	return z;
}

template <class T>
void Position<T>::setX(T abscissa)
{
	x = abscissa;
}

template <class T>
void Position<T>::setY(T ordinate)
{
	y = ordinate;
}

template <class T>
void Position<T>::setZ(T depth)
{
	z = depth;
}

template <class T>
void Position<T>::setPosition(T abscissa, T ordinate, T depth)
{
	x = abscissa;
	y = ordinate;
	z = depth;
}

#endif // !POSITION_H_
