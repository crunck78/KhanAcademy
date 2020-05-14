#pragma once
#include <iostream>

//ASCII CODE FOR MATHEMATICAL OPERATIONS
enum BinaryOperations
{
	EQUAL = 61, ADDITION = 43, SUBSTRACTION = 45, MULTIPLICATION = 42, DIVISION = 47, LCM = 109
};

//TODO: Implement Unary Operations
enum UnaryOperations
{
	ABSOLUTE = 97, OPPOSITE = 111
};

enum Converstions
{
	MIXEDNUM_TO_IMPRFRACT = 1, IMPRFRACT_TO_MIXEDNUM = -1, 
};

//TODO
static const std::vector<char> validOperations = { EQUAL, ADDITION, SUBSTRACTION, MULTIPLICATION, DIVISION };

template<typename Number>
bool isPossitive(const Number &a)
{
	return (a > 0);
}

template<typename Number>
bool isNegative(const Number &a)
{
	return (a < 0);
}

template<typename Number>
bool isOpposite(const Number &a, const Number &b)
{
	return a == -b;
}

template<typename Number>
bool isEven(const Number &a)
{
	return (a % 2) == 0;
}

template<typename Number>
bool isDivisible(const Number &a, const Number &b)
{
	return (a % b) == 0;
}

template<typename Number>
const Number midValue(const Number &a, const Number &b)
{
	return (a + b) / 2;
}


template<typename Number>
const Number getSum(const Number &a, const Number &b)
{
	return a + b;
}

template<typename Number>
const Number getSub(const Number &a, const Number &b)
{
	return a - b;
}

template<typename Number>
const Number getProd(const Number &a, const Number &b)
{
	return a * b;
}

template<typename Number>
const Number getDiv(const Number &a, const Number &b)
{
	if (b == 0)
		std::cerr << "ERROR::ARITHMETIC::LINE78::Division by 0 is undefinde!" << std::endl;
	return a / b;
}

template<typename Number>
const unsigned int getRemainder(const Number &a, const Number &b)
{
	return a % b;
}


const unsigned int getLeastCommonMultiple(const unsigned int a, const unsigned int b)
{
	unsigned int aMultiple = a;
	unsigned int bMultiple = b;
	while (aMultiple != bMultiple)
	{
		if (aMultiple < bMultiple)
			aMultiple += a;
		else
			bMultiple += b;
	}
	return aMultiple;
}

//TODO
const unsigned int getGreatestCommonDivisor(const unsigned int a, const unsigned int b)
{
	unsigned int gcd = 1; //smallest common divisor
	unsigned int biggerDivisor;
	unsigned int smallerDivisor;
	
	if(a > b)
	{
		biggerDivisor = a;
		smallerDivisor = b;
	}
	else
	{
		biggerDivisor = b;
		smallerDivisor = a;
	}
	
	if( isDivisible(biggerDivisor, smallerDivisor))
	{
		gcd = smallerDivisor;
	}
	else
	{
		unsigned int divisorTest = 2;// smallest prime factor
		while(divisorTest < smallerDivisor)
		{
			if(isDivisible(biggerDivisor,divisorTest) && isDivisible(smallerDivisor,divisorTest))
			{
				gcd *= divisorTest;
				biggerDivisor /= divisorTest;
				smallerDivisor /= divisorTest;
			}
			else
				divisorTest++;
		}
	}
	return gcd;
}

template<typename Number>
const Number getResult(const Number &a, const Number &b, const char operation)
{
	Number result = 0;
	switch ((int)operation)
	{
	case ADDITION: result = getSum(a, b); break;
	case SUBSTRACTION: result = getSub(a, b); break;
	case MULTIPLICATION: result = getProd(a, b); break;
	case DIVISION: result = getDiv(a, b); break;
	default: std::cerr << "UNKNOWN OPERATION OF SIGN: " << operation << std::endl;
		std::cerr << "RETURN 0" << std::endl;
		break;
	}
	return result;
}

template<typename Number>
const Number getOpposite(const Number &a)
{
	return 0 - a;
}

template<typename Number>
const Number getAbsoluteValue(const Number &a)
{
	if (isNegative(a))
		return getOpposite(a);
	return a;
}

template<typename Number>
const Number getResult(const Number &a, const char operation)
{
	Number result = 0;
	switch ((int)operation)
	{
	case OPPOSITE: result = getOpposite(a); break;
	case ABSOLUTE: result = getAbsoluteValue(a); break;
	default: std::cerr << "UNKNOWN OPERATION OF SIGN: " << operation << std::endl;
		std::cerr << "RETURN 0" << std::endl;
		break;
	}
	return result;
}

/*class WholeNumber
{
private:
	unsigned int m_wholeNumber;
	
public:
	WholeNumber()
		:m_wholeNumber(0) {}
	WholeNumber(const int n)
		:m_wholeNumber(n) {}
	WholeNumber(const WholeNumber &other)
		:m_wholeNumber(other.m_wholeNumber) {}

	WholeNumber& operator=(const WholeNumber &rhs)
	{
		if (this != &rhs)
		{
			this->m_wholeNumber = rhs.m_wholeNumber;
		}
		return *this;
	}

	WholeNumber& operator+=(const WholeNumber &rhs)
	{
		this->m_wholeNumber = this->m_wholeNumber + rhs.m_wholeNumber;
		return *this;
	}

	friend WholeNumber operator+(WholeNumber lhs, const WholeNumber &rhs)
	{
		lhs += rhs;
		return lhs;
	}

	WholeNumber& operator-=(const WholeNumber &rhs)
	{
		if (this->m_wholeNumber < rhs.m_wholeNumber)
			std::cerr << "Can not substract a bigger Whole number from a smaller Whole number!" << std::endl;
		else
			this->m_wholeNumber = this->m_wholeNumber - rhs.m_wholeNumber;
		return *this;
	}

	friend WholeNumber operator-(WholeNumber lhs, const WholeNumber &rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	WholeNumber& operator-()
	{
		std::cerr << "Whole numbers have no opposites!" << std::endl;
		return *this;
	}

	WholeNumber& operator++()
	{
		this->m_wholeNumber++;
		return *this;
	}

	WholeNumber& operator++(int)
	{
		this->m_wholeNumber++;
		return *this;
	}

	WholeNumber& operator--()
	{
		if (this->m_wholeNumber == 0)
			std::cerr << "Whole numbers can not be smaller then 0!" << std::endl;
		else
			this->m_wholeNumber--;
		return *this;
	}

	WholeNumber& operator--(int)
	{
		if (this->m_wholeNumber == 0)
			std::cerr << "Whole numbers can not be smaller then 0!" << std::endl;
		else
			this->m_wholeNumber--;
		return *this;
	}

	WholeNumber& operator*=(const WholeNumber &rhs)
	{
		this->m_wholeNumber = this->m_wholeNumber * rhs.m_wholeNumber;
		return *this;
	}

	friend WholeNumber operator*(WholeNumber lhs, const WholeNumber &rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	WholeNumber& operator/=(const WholeNumber &rhs)
	{
		this->m_wholeNumber = this->m_wholeNumber / rhs.m_wholeNumber;
		return *this;
	}

	friend WholeNumber operator/(WholeNumber lhs, const WholeNumber &rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	friend bool operator==(const WholeNumber &lhs, const WholeNumber &rhs)
	{
		return lhs.m_wholeNumber == rhs.m_wholeNumber;
	}

	friend bool operator!=(const WholeNumber &lhs, const WholeNumber &rhs) { return !operator==(lhs, rhs); }

	friend bool operator< (const WholeNumber &lhs, const WholeNumber &rhs)
	{
		return lhs.m_wholeNumber < rhs.m_wholeNumber;
	}

	friend bool operator> (const WholeNumber &lhs, const WholeNumber &rhs) { return operator< (rhs, lhs); }
	friend bool operator<=(const WholeNumber &lhs, const WholeNumber &rhs) { return !operator> (lhs, rhs); }
	friend bool operator>=(const WholeNumber &lhs, const WholeNumber &rhs) { return !operator< (lhs, rhs); }


	friend std::ostream& operator<<(std::ostream& os, const WholeNumber &obj)
	{
		os << obj.m_wholeNumber;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, WholeNumber &obj)
	{
		std::cout << "Enter Whole number(Only Positive Integer Accepted): ";
		is >> obj.m_wholeNumber;
		return is;
	}
};*/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;//if 0, is undefinde, if < 0 assigned the numerator and make denominator possitive

public:
	Fraction()
		:m_numerator(0), m_denominator(1) {}
	Fraction(const int n)
		:m_numerator(n), m_denominator(1) {}

	Fraction(const int n, const int d)
	{
		set(n, d);
	}

	Fraction(const Fraction &other)
	{
		set(other.m_numerator, other.m_denominator);
	}

	Fraction& operator=(const Fraction &rhs)
	{
		if (this != &rhs)
		{
			this->set(rhs.m_numerator, rhs.m_denominator);
		}
		return *this;
	}

	Fraction& operator+=(const Fraction &rhs)
	{
		if (this->m_denominator != rhs.m_denominator)
		{
			const int leastCommonDenominator = (int)getLeastCommonMultiple(this->m_denominator, rhs.m_denominator);
			this->m_numerator = (this->m_numerator * leastCommonDenominator / this->m_denominator) + (rhs.m_numerator * leastCommonDenominator / rhs.m_denominator);
			this->m_denominator = leastCommonDenominator;
		}
		else
			this->m_numerator += rhs.m_numerator;
		return *this;
	}

	friend Fraction operator+(Fraction lhs, const Fraction &rhs)
	{
		lhs += rhs;
		return lhs;
	}

	Fraction& operator-=(const Fraction &rhs)
	{
		if (this->m_denominator != rhs.m_denominator)
		{
			const int leastCommonDenominator = (int)getLeastCommonMultiple(this->m_denominator, rhs.m_denominator);
			this->m_numerator = (this->m_numerator * leastCommonDenominator / this->m_denominator) - (rhs.m_numerator * leastCommonDenominator / rhs.m_denominator);
			this->m_denominator = leastCommonDenominator;
		}
		else
			this->m_numerator -= rhs.m_numerator;
		return *this;
	}

	friend Fraction operator-(Fraction lhs, const Fraction &rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	Fraction operator-()
	{
		return Fraction(-this->m_numerator, this->m_denominator);
	}

	Fraction& operator++()
	{
		this->m_numerator += this->m_denominator;
		return *this;
	}

	Fraction& operator++(int)
	{
		this->m_numerator += this->m_denominator;
		return *this;
	}

	Fraction& operator--()
	{
		this->m_numerator -= this->m_denominator;
		return *this;
	}

	Fraction& operator--(int)
	{
		this->m_numerator -= this->m_denominator;
		return *this;
	}

	Fraction& operator*=(const Fraction &rhs)
	{
		this->m_numerator = this->m_numerator * rhs.m_numerator;
		this->m_denominator = this->m_denominator * rhs.m_denominator;
		return *this;
	}

	friend Fraction operator*(Fraction lhs, const Fraction &rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Fraction& operator/=(const Fraction &rhs)
	{
		this->m_numerator = this->m_numerator * rhs.m_denominator;
		this->m_denominator = this->m_denominator * rhs.m_numerator;
		return *this;
	}

	friend Fraction operator/(Fraction lhs, const Fraction &rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	friend bool operator==(const Fraction &lhs, const Fraction &rhs)
	{
		return (lhs.m_numerator * rhs.m_denominator) == (lhs.m_denominator * rhs.m_numerator);
	}

	friend bool operator!=(const Fraction &lhs, const Fraction &rhs) { return !operator==(lhs, rhs); }

	friend bool operator< (const Fraction &lhs, const Fraction &rhs)
	{
		if (lhs.m_denominator != rhs.m_denominator)
			return (lhs.m_numerator * rhs.m_denominator) < (rhs.m_numerator * lhs.m_denominator);
		else
			return lhs.m_numerator < rhs.m_numerator;
	}

	friend bool operator> (const Fraction &lhs, const Fraction &rhs) { return operator< (rhs, lhs); }
	friend bool operator<=(const Fraction &lhs, const Fraction &rhs) { return !operator> (lhs, rhs); }
	friend bool operator>=(const Fraction &lhs, const Fraction &rhs) { return !operator< (lhs, rhs); }


	friend std::ostream& operator<<(std::ostream& os, const Fraction &obj)
	{
		os << obj.m_numerator << '/' << obj.m_denominator;
		return os;
	}

	//USE INPUT HELP CLASS TO SET FRACTION CORRECT
	friend std::istream& operator>>(std::istream& is, Fraction &obj)
	{
		std::cout << "Enter numerator: ";
		is >> obj.m_numerator;
		std::cout << "Enter denominator: ";
		is >> obj.m_denominator;
		while (obj.m_denominator == 0)
		{
			std::cout << "Fraction is undefinde if denominator equals to 0!" << std::endl;
			std::cout << "Enter denominator: ";
			is >> obj.m_denominator;
		}
		return is;
	}
	
	void set(const int n, const int d)
	{
		if (d < 0)
		{
			m_numerator = -n;
			m_denominator = -d;
		}
		else
		{
			m_numerator = n;
			m_denominator = d;
		}
	}

	const int getNumerator() const
	{
		return m_numerator;
	}

	const int getDenominator() const
	{
		return m_denominator;
	}

	friend void toCommonDenominators(Fraction &lhs, Fraction &rhs)
	{
		//find smallest common multiple of the fractions denominators
		const int leastCommonDenominator = (int)getLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);

		//first set the numerators(we need the original denominator unchanged to set the correct numerator)
		lhs.m_numerator *= leastCommonDenominator / lhs.m_denominator;
		rhs.m_numerator *= leastCommonDenominator / rhs.m_denominator;

		//second set the denominators
		lhs.m_denominator = leastCommonDenominator;
		rhs.m_denominator = leastCommonDenominator;
	}

	const int getResult() const
	{
		return (m_numerator / m_denominator);
	}

	const unsigned int getRemainder() const
	{
		return (m_numerator % m_denominator);
	}

	//TODO
	const Fraction getSimplification()
	{
		Fraction simplification;
		int gcd = (int)getGreatestCommonDivisor(getAbsoluteValue(m_numerator), m_denominator);
		simplification.set(m_numerator / gcd, m_denominator / gcd );
		return simplification;
	}

	bool isUndefined()
	{
		return m_denominator == 0;
	}

	bool isImproper()
	{
		return getAbsoluteValue(m_numerator) >= m_denominator;
	}

	bool isUnit()
	{
		return (m_numerator == 1 || m_numerator == -1);
	}
};

class MixedNumber
{
private:
	int m_wholePart;
	Fraction m_proper;
public:
	MixedNumber()
		:m_wholePart(0), m_proper(0) {}
		
	MixedNumber( const int wp, const Fraction &proper)
		:m_wholePart(wp), m_proper(proper) {}

	MixedNumber(const Fraction &improper)
		:m_wholePart(improper.getResult()), m_proper(improper.getRemainder(), improper.getDenominator()) {}

	MixedNumber(const MixedNumber &other)
	{
		m_wholePart = other.m_wholePart;
		m_proper = other.m_proper;
	}
	
	//TODO
	MixedNumber& operator=(const MixedNumber &rhs)
	{
		if (this != &rhs)
		{
			//TODO
			this->m_wholePart = rhs.m_wholePart;
			this->m_proper = rhs.m_proper;
		}
		return *this;
	}
	
	//TODO
	MixedNumber& operator+=(const MixedNumber &rhs)
	{
		/*Fraction improper = Fraction(this->m_wholePart) + this->m_proper + Fraction(rhs.m_wholePart) + rhs.m_proper;
		*this = MixedNumber(improper);*/
		this->m_wholePart += rhs.m_wholePart;
		this->m_proper += rhs.m_proper;
		return *this;
	}
	
	friend MixedNumber operator+(MixedNumber lhs, const MixedNumber &rhs)
	{
		lhs += rhs;
		return lhs;
	}
	
	
	MixedNumber& operator-=(const MixedNumber &rhs)
	{
		/*Fraction improper = (Fraction(this->m_wholePart) + this->m_proper) - (Fraction(rhs.m_wholePart) + rhs.m_proper);
		*this = MixedNumber(improper);*/
		this->m_wholePart -= rhs.m_wholePart;
		this->m_proper -= rhs.m_proper;
		return *this;
	}
	
	friend MixedNumber operator-(MixedNumber lhs, const MixedNumber &rhs)
	{
		lhs -= rhs;
		return lhs;
	}
	
	MixedNumber operator-()
	{
		return MixedNumber(-this->m_wholePart, -this->m_proper);
	}
	
	//TODO
	MixedNumber& operator++()
	{
		this->m_wholePart++;
		return *this;
	}
	
	MixedNumber& operator++(int)
	{
		this->m_wholePart++;
		return *this;
	}
	
	MixedNumber& operator--()
	{
		this->m_wholePart--;
		return *this;
	}
	
	MixedNumber& operator--(int)
	{
		this->m_wholePart--;
		return *this;
	}
	
	MixedNumber& operator*=(const MixedNumber &rhs)
	{
		//TODO
		
		return *this;
	}

	friend MixedNumber operator*(MixedNumber lhs, const MixedNumber &rhs)
	{
		lhs *= rhs;
		return lhs;
	}
	
	MixedNumber& operator/=(const MixedNumber &rhs)
	{
		//TODO
		return *this;
	}

	friend MixedNumber operator/(MixedNumber lhs, const MixedNumber &rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	const Fraction getImproperFraction() const
	{
		Fraction improper;
		const int numerator = m_wholePart * m_proper.getDenominator() + m_proper.getNumerator();
		improper.set(numerator, m_proper.getDenominator());
		return improper;
	}

	const MixedNumber getMixedNumber(const Fraction &improper)
	{
		const MixedNumber converted(improper);
		return converted;
	}

	//USE INPUT HELP CLASS TO SET FRACTION CORRECT
	friend std::istream& operator>>(std::istream& is, MixedNumber &obj)
	{
		std::cout << "Enter Whole Part:";
		is >> obj.m_wholePart;
		std::cout << "Enter Proper Fraction:";
		is >> obj.m_proper;
		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const MixedNumber &obj)
	{
		os << obj.m_wholePart << '(' << obj.m_proper << ')';
		return os;
	}
};
