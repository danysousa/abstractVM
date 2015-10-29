#ifndef INT32_HPP
# define INT32_HPP
# include <IOperand.hpp>
# include <iostream>

class Int32 : public IOperand
{
	public:
		Int32( eOperandType, std::string value );
		Int32(Int32 const & cpy);
		virtual ~Int32( void );


		virtual int				getPrecision( void ) const;
		std::string				getValStr( void ) const;
		int						getVal( void ) const;
		virtual eOperandType	getType( void ) const;

		Int32						operator=( Int32 const & cpy );
		virtual IOperand const * 	operator+( IOperand const & rhs ) const;
		virtual IOperand const * 	operator-( IOperand const & rhs ) const;
		virtual IOperand const * 	operator*( IOperand const & rhs ) const;
		virtual IOperand const * 	operator/( IOperand const & rhs ) const;
		virtual IOperand const *	operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

	private:
		Int32();
		eOperandType	type;
		std::string		val_str;
		int				val;
};

#endif