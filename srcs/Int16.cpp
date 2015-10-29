#include <Int16.hpp>

Int16::Int16( eOperandType type, std::string value ) : type(type), val_str(value), val(0)
{
	std::cout << "Int16 create" <<std::endl;
	val++;
}

Int16::Int16(Int16 const & cpy)
{
	*this = cpy;
}

Int16::~Int16()
{
}

Int16	Int16::operator=( Int16 const & cpy )
{
	this->val_str = cpy.getValStr();
	this->val = cpy.getVal();
	this->type = cpy.getType();

	return (*this);
}

/*
** GET & SET
*/
std::string		Int16::getValStr(void) const
{
	return (this->val_str);
}

int				Int16::getVal(void) const
{
	return (this->val);
}

int Int16::getPrecision( void ) const
{
	return (0);
}

eOperandType Int16::getType( void ) const
{
	return (this->type);
}

/*
** METHODS
*/

IOperand const * Int16::operator+( IOperand const & rhs ) const
{
	Int16	*result = new Int16(INT16, this->val_str);
	if (rhs.getType() == INT16)
		std::cout << "Int16 opeartor +" << std::endl;

	return (result);
}

IOperand const * Int16::operator-( IOperand const & rhs ) const
{
	Int16	*result = new Int16(INT16, this->val_str);
	if (rhs.getType() == INT16)
		std::cout << "Int16 opeartor -" << std::endl;

	return (result);
}

IOperand const * Int16::operator*( IOperand const & rhs ) const
{
	Int16	*result = new Int16(INT16, this->val_str);
	if (rhs.getType() == INT16)
		std::cout << "Int16 opeartor *" << std::endl;

	return (result);
}

IOperand const * Int16::operator/( IOperand const & rhs ) const
{
	Int16	*result = new Int16(INT16, this->val_str);
	if (rhs.getType() == INT16)
		std::cout << "Int16 opeartor /" << std::endl;

	return (result);
}

IOperand const * Int16::operator%( IOperand const & rhs ) const
{
	Int16	*result = new Int16(INT16, this->val_str);
	if (rhs.getType() == INT16)
		std::cout << "Int16 opeartor %" << std::endl;

	return (result);
}

std::string const & Int16::toString( void ) const
{
	return (this->val_str);
}
