#include <Float.hpp>

Float::Float( eOperandType type, std::string value ) : type(type), val_str(value), val(0)
{
	std::cout << "Float create" <<std::endl;
	val++;
}

Float::Float(Float const & cpy)
{
	*this = cpy;
}

Float::~Float()
{
}

Float	Float::operator=( Float const & cpy )
{
	this->val_str = cpy.getValStr();
	this->val = cpy.getVal();
	this->type = cpy.getType();

	return (*this);
}

/*
** GET & SET
*/
std::string		Float::getValStr(void) const
{
	return (this->val_str);
}

int				Float::getVal(void) const
{
	return (this->val);
}

int Float::getPrecision( void ) const
{
	return (0);
}

eOperandType Float::getType( void ) const
{
	return (this->type);
}

/*
** METHODS
*/

IOperand const * Float::operator+( IOperand const & rhs ) const
{
	Float	*result = new Float(FLOAT, this->val_str);
	if (rhs.getType() == FLOAT)
		std::cout << "Float opeartor +" << std::endl;

	return (result);
}

IOperand const * Float::operator-( IOperand const & rhs ) const
{
	Float	*result = new Float(FLOAT, this->val_str);
	if (rhs.getType() == FLOAT)
		std::cout << "Float opeartor -" << std::endl;

	return (result);
}

IOperand const * Float::operator*( IOperand const & rhs ) const
{
	Float	*result = new Float(FLOAT, this->val_str);
	if (rhs.getType() == FLOAT)
		std::cout << "Float opeartor *" << std::endl;

	return (result);
}

IOperand const * Float::operator/( IOperand const & rhs ) const
{
	Float	*result = new Float(FLOAT, this->val_str);
	if (rhs.getType() == FLOAT)
		std::cout << "Float opeartor /" << std::endl;

	return (result);
}

IOperand const * Float::operator%( IOperand const & rhs ) const
{
	Float	*result = new Float(FLOAT, this->val_str);
	if (rhs.getType() == FLOAT)
		std::cout << "Float opeartor %" << std::endl;

	return (result);
}

std::string const & Float::toString( void ) const
{
	return (this->val_str);
}
