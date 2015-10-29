#ifndef INT8_HPP
# define INT8_HPP
# include <IOperand.hpp>
# include <iostream>

class Int8 : public IOperand
{
	public:
		Int8( eOperandType, std::string value );
		Int8(Int8 const & cpy);
		virtual ~Int8( void );


		virtual int				getPrecision( void ) const;
		std::string				getValStr( void ) const;
		int						getVal( void ) const;
		virtual eOperandType	getType( void ) const;

		Int8						operator=( Int8 const & cpy );
		virtual IOperand const * 	operator+( IOperand const & rhs ) const;
		virtual IOperand const * 	operator-( IOperand const & rhs ) const;
		virtual IOperand const * 	operator*( IOperand const & rhs ) const;
		virtual IOperand const * 	operator/( IOperand const & rhs ) const;
		virtual IOperand const *	operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

	private:
		Int8();
		eOperandType	type;
		std::string		val_str;
		int				val;
};

#endif