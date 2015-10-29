#include <Program.hpp>

Program::Program()
{

}

Program::Program(std::vector<stringV> const *list) : cmd(list)
{
	// this->createOperand(INT8, "1");
	this->launch();
}

Program::Program(Program const & cpy)
{
	*this = cpy;
}

Program::~Program()
{
}

Program	Program::operator=( Program const & cpy )
{
	this->cmd = cpy.getCmd();

	return (*this);
}

/*
** GET & SET
*/
std::vector<stringV> const	*Program::getCmd( void ) const
{
	return (this->cmd);
}

/*
** METHODS
*/

void	Program::launch()
{
	 std::map<std::string, fnPtr> inst = {
		{"push", &Program::push},
		{"assert", &Program::assert},
		{"pop", &Program::pop},
		{"dump", &Program::dump},
		{"add", &Program::add},
		{"sub", &Program::sub},
		{"mul", &Program::mul},
		{"div", &Program::div},
		{"mod", &Program::mod},
		{"print", &Program::print},
		{"exit", &Program::exit}
	};

	for (size_t i = 0; i < this->cmd->size(); ++i)
	{
		fnPtr f = inst.at( this->cmd->at(i).at(0) );
		(this->*f)( this->cmd->at(i) );
	}

}

void		Program::push(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::assert(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::pop(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::dump(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::add(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::sub(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::mul(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::div(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::mod(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::print(stringV av)
{
	std::cout << av[0] << std::endl;
}
void		Program::exit(stringV av)
{
	std::cout << av[0] << std::endl;
}

/*
** CREATE
*/
IOperand const *		Program::createOperand( eOperandType type, std::string const & value ) const
{
	if ( type == INT8 )
		std::cout << value <<std::endl;
	else
		std::cout << value <<std::endl;
	return (new Int8(type, value));

}

IOperand const *		Program::createInt8( std::string const & value ) const
{
	std::cout << value << std::endl;
	return (new Int8(INT8, value));
}

IOperand const *		Program::createInt16( std::string const & value ) const
{
	std::cout << value << std::endl;
	return (new Int16(INT16, value));
}

IOperand const *		Program::createInt32( std::string const & value ) const
{
	std::cout << value << std::endl;
	return (new Int32(INT32, value));
}

IOperand const *		Program::createFloat( std::string const & value ) const
{
	std::cout << value << std::endl;
	return (new Float(FLOAT, value));
}

IOperand const *		Program::createDouble( std::string const & value ) const
{
	std::cout << value << std::endl;
	return (new Double(DOUBLE, value));
}
