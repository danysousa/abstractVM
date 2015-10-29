#ifndef FLOAT_HPP
# define FLOAT_HPP
# include <IOperand.hpp>
# include <iostream>

class Float : public IOperand
{
	public:
		Float( eOperandType, std::string value );
		Float(Float const & cpy);
		virtual ~Float( void );


		virtual int				getPrecision( void ) const;
		std::string				getValStr( void ) const;
		int						getVal( void ) const;
		virtual eOperandType	getType( void ) const;

		Float						operator=( Float const & cpy );
		virtual IOperand const * 	operator+( IOperand const & rhs ) const;
		virtual IOperand const * 	operator-( IOperand const & rhs ) const;
		virtual IOperand const * 	operator*( IOperand const & rhs ) const;
		virtual IOperand const * 	operator/( IOperand const & rhs ) const;
		virtual IOperand const *	operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

	private:
		Float();
		eOperandType	type;
		std::string		val_str;
		int				val;
};

#endif