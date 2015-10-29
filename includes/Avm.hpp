#ifndef AVM_HPP
# define AVM_HPP
# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include <regex>
# include <Program.hpp>
# include <IOperand.hpp>

typedef std::vector<std::string> stringV;

class Avm
{
	public:
		Avm(const char *filename);
		Avm(Avm const & cpy);
		~Avm();

		Avm	operator=( Avm const & cpy );

		/*
		** GET & SET
		*/
		const char	*getFile(void) const;
		std::vector<stringV>	getCmd(void) const;

		/*
		** METHODS
		*/
		void		addInstruction( std::string i );
		bool		isValidInst( stringV argv ) const;
		bool		isValidValue( stringV argv ) const;


	private:
		Avm();
		const char				*file;
		std::vector<stringV>	cmd;
		Program					*prog;
};

#endif