#ifndef DOUBLE_HPP
# define DOUBLE_HPP
# include <IOperand.hpp>
# include <iostream>

class Double : public IOperand
{
	public:
		Double( eOperandType, std::string value );
		Double(Double const & cpy);
		virtual ~Double( void );


		virtual int				getPrecision( void ) const;
		std::string				getValStr( void ) const;
		int						getVal( void ) const;
		virtual eOperandType	getType( void ) const;

		Double						operator=( Double const & cpy );
		virtual IOperand const * 	operator+( IOperand const & rhs ) const;
		virtual IOperand const * 	operator-( IOperand const & rhs ) const;
		virtual IOperand const * 	operator*( IOperand const & rhs ) const;
		virtual IOperand const * 	operator/( IOperand const & rhs ) const;
		virtual IOperand const *	operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

	private:
		Double();
		eOperandType	type;
		std::string		val_str;
		int				val;
};

#endif