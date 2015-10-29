#include <Int32.hpp>

Int32::Int32( eOperandType type, std::string value ) : type(type), val_str(value), val(0)
{
	std::cout << "Int32 create" <<std::endl;
	val++;
}

Int32::Int32(Int32 const & cpy)
{
	*this = cpy;
}

Int32::~Int32()
{
}

Int32	Int32::operator=( Int32 const & cpy )
{
	this->val_str = cpy.getValStr();
	this->val = cpy.getVal();
	this->type = cpy.getType();

	return (*this);
}

/*
** GET & SET
*/
std::string		Int32::getValStr(void) const
{
	return (this->val_str);
}

int				Int32::getVal(void) const
{
	return (this->val);
}

int Int32::getPrecision( void ) const
{
	return (0);
}

eOperandType Int32::getType( void ) const
{
	return (this->type);
}

/*
** METHODS
*/

IOperand const * Int32::operator+( IOperand const & rhs ) const
{
	Int32	*result = new Int32(INT32, this->val_str);
	if (rhs.getType() == INT32)
		std::cout << "Int32 opeartor +" << std::endl;

	return (result);
}

IOperand const * Int32::operator-( IOperand const & rhs ) const
{
	Int32	*result = new Int32(INT32, this->val_str);
	if (rhs.getType() == INT32)
		std::cout << "Int32 opeartor -" << std::endl;

	return (result);
}

IOperand const * Int32::operator*( IOperand const & rhs ) const
{
	Int32	*result = new Int32(INT32, this->val_str);
	if (rhs.getType() == INT32)
		std::cout << "Int32 opeartor *" << std::endl;

	return (result);
}

IOperand const * Int32::operator/( IOperand const & rhs ) const
{
	Int32	*result = new Int32(INT32, this->val_str);
	if (rhs.getType() == INT32)
		std::cout << "Int32 opeartor /" << std::endl;

	return (result);
}

IOperand const * Int32::operator%( IOperand const & rhs ) const
{
	Int32	*result = new Int32(INT32, this->val_str);
	if (rhs.getType() == INT32)
		std::cout << "Int32 opeartor %" << std::endl;

	return (result);
}

std::string const & Int32::toString( void ) const
{
	return (this->val_str);
}
