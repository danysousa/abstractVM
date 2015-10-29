#include <Int8.hpp>

Int8::Int8( eOperandType type, std::string value ) : type(type), val_str(value), val(0)
{
	std::cout << "INT8 create" <<std::endl;
	val++;
}

Int8::Int8(Int8 const & cpy)
{
	*this = cpy;
}

Int8::~Int8()
{
}

Int8	Int8::operator=( Int8 const & cpy )
{
	this->val_str = cpy.getValStr();
	this->val = cpy.getVal();
	this->type = cpy.getType();

	return (*this);
}

/*
** GET & SET
*/
std::string		Int8::getValStr(void) const
{
	return (this->val_str);
}

int				Int8::getVal(void) const
{
	return (this->val);
}

int Int8::getPrecision( void ) const
{
	return (0);
}

eOperandType Int8::getType( void ) const
{
	return (this->type);
}

/*
** METHODS
*/

IOperand const * Int8::operator+( IOperand const & rhs ) const
{
	Int8	*result = new Int8(INT8, this->val_str);
	if (rhs.getType() == INT8)
		std::cout << "INT8 opeartor +" << std::endl;

	return (result);
}

IOperand const * Int8::operator-( IOperand const & rhs ) const
{
	Int8	*result = new Int8(INT8, this->val_str);
	if (rhs.getType() == INT8)
		std::cout << "INT8 opeartor -" << std::endl;

	return (result);
}

IOperand const * Int8::operator*( IOperand const & rhs ) const
{
	Int8	*result = new Int8(INT8, this->val_str);
	if (rhs.getType() == INT8)
		std::cout << "INT8 opeartor *" << std::endl;

	return (result);
}

IOperand const * Int8::operator/( IOperand const & rhs ) const
{
	Int8	*result = new Int8(INT8, this->val_str);
	if (rhs.getType() == INT8)
		std::cout << "INT8 opeartor /" << std::endl;

	return (result);
}

IOperand const * Int8::operator%( IOperand const & rhs ) const
{
	Int8	*result = new Int8(INT8, this->val_str);
	if (rhs.getType() == INT8)
		std::cout << "INT8 opeartor %" << std::endl;

	return (result);
}

std::string const & Int8::toString( void ) const
{
	return (this->val_str);
}
