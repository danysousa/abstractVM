#ifndef PROGRAM_HPP
# define PROGRAM_HPP
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <IOperand.hpp>
# include <Int8.hpp>
# include <Int16.hpp>
# include <Int32.hpp>
# include <Float.hpp>
# include <Double.hpp>

typedef std::vector<std::string> stringV;

class Program
{
	public:
		Program(std::vector<stringV> const *list);
		Program(Program const & cpy);
		~Program();

		Program	operator=( Program const & cpy );

		/*
		** GET & SET
		*/
		std::vector<stringV> const	*getCmd(void) const;

		/*
		** METHODS
		*/
		void	launch();

		void	push(stringV av);
		void	assert(stringV av);
		void	pop(stringV av);
		void	dump(stringV av);
		void	add(stringV av);
		void	sub(stringV av);
		void	mul(stringV av);
		void	div(stringV av);
		void	mod(stringV av);
		void	print(stringV av);
		void	exit(stringV av);

		/*
		** CREATE
		*/
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

	private:
		Program();
		std::vector<stringV> const	*cmd;
		std::vector<IOperand>		stack;
};

typedef void(Program::*fnPtr)(stringV);

#endif