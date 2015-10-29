#ifndef INT16_HPP
# define INT16_HPP
# include <IOperand.hpp>
# include <iostream>

class Int16 : public IOperand
{
	public:
		Int16( eOperandType, std::string value );
		Int16(Int16 const & cpy);
		virtual ~Int16( void );


		virtual int				getPrecision( void ) const;
		std::string				getValStr( void ) const;
		int						getVal( void ) const;
		virtual eOperandType	getType( void ) const;

		Int16						operator=( Int16 const & cpy );
		virtual IOperand const * 	operator+( IOperand const & rhs ) const;
		virtual IOperand const * 	operator-( IOperand const & rhs ) const;
		virtual IOperand const * 	operator*( IOperand const & rhs ) const;
		virtual IOperand const * 	operator/( IOperand const & rhs ) const;
		virtual IOperand const *	operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

	private:
		Int16();
		eOperandType	type;
		std::string		val_str;
		int				val;
};

#endif