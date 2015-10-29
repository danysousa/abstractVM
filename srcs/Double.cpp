#include <Double.hpp>

Double::Double( eOperandType type, std::string value ) : type(type), val_str(value), val(0)
{
	std::cout << "Double create" <<std::endl;
	val++;
}

Double::Double(Double const & cpy)
{
	*this = cpy;
}

Double::~Double()
{
}

Double	Double::operator=( Double const & cpy )
{
	this->val_str = cpy.getValStr();
	this->val = cpy.getVal();
	this->type = cpy.getType();

	return (*this);
}

/*
** GET & SET
*/
std::string		Double::getValStr(void) const
{
	return (this->val_str);
}

int				Double::getVal(void) const
{
	return (this->val);
}

int Double::getPrecision( void ) const
{
	return (0);
}

eOperandType Double::getType( void ) const
{
	return (this->type);
}

/*
** METHODS
*/

IOperand const * Double::operator+( IOperand const & rhs ) const
{
	Double	*result = new Double(DOUBLE, this->val_str);
	if (rhs.getType() == DOUBLE)
		std::cout << "Double opeartor +" << std::endl;

	return (result);
}

IOperand const * Double::operator-( IOperand const & rhs ) const
{
	Double	*result = new Double(DOUBLE, this->val_str);
	if (rhs.getType() == DOUBLE)
		std::cout << "Double opeartor -" << std::endl;

	return (result);
}

IOperand const * Double::operator*( IOperand const & rhs ) const
{
	Double	*result = new Double(DOUBLE, this->val_str);
	if (rhs.getType() == DOUBLE)
		std::cout << "Double opeartor *" << std::endl;

	return (result);
}

IOperand const * Double::operator/( IOperand const & rhs ) const
{
	Double	*result = new Double(DOUBLE, this->val_str);
	if (rhs.getType() == DOUBLE)
		std::cout << "Double opeartor /" << std::endl;

	return (result);
}

IOperand const * Double::operator%( IOperand const & rhs ) const
{
	Double	*result = new Double(DOUBLE, this->val_str);
	if (rhs.getType() == DOUBLE)
		std::cout << "Double opeartor %" << std::endl;

	return (result);
}

std::string const & Double::toString( void ) const
{
	return (this->val_str);
}
