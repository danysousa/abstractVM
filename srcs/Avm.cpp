#include <Avm.hpp>

Avm::Avm()
{
}

Avm::Avm(const char *filename) : file(filename)
{
	std::string			line;
	std::ifstream		fd( this->file );

	if (!fd.is_open())
	{
		std::cerr << "Unable to open" << this->file << std::endl;
		exit(-1);
	}
	while ( std::getline( fd,line ) )
		this->addInstruction( line );
	fd.close();

	this->prog = new Program(&this->cmd);
}

Avm::Avm(Avm const & cpy)
{
	*this = cpy;
}

Avm::~Avm()
{
}

Avm	Avm::operator=( Avm const & cpy )
{
	this->file = cpy.getFile();
	this->cmd = cpy.getCmd();

	return (*this);
}

/*
** GET & SET
*/
const char				*Avm::getFile( void ) const
{
	return (this->file);
}

std::vector<stringV>	Avm::getCmd( void ) const
{
	return (this->cmd);
}

/*
** METHODS
*/
void		Avm::addInstruction( std::string i )
{
	stringV			av;
	int				j = 0;

	i = i.substr(0, i.find(";"));
	if ( i.size() == 0 )
		return ;

	while ( i.find(' ') != i.npos )
	{
		if ( i.find(' ') == 0 )
		{
			i = i.substr( i.find(' ') + 1 );
			continue;
		}
		if ( j >= 1 )
		{
			std::cerr << "Syntax error in " << this->file << std::endl;
			exit(-2);
		}
		av.insert( av.begin(), i.substr( 0, i.find(' ') ) );
		i = i.substr( i.find(' ') + 1 );
		j++;
	}
	av.push_back( i );

	if ( this->isValidInst( av ) == false )
	{
		std::cerr << "Syntax error in " << this->file << " :" << std::endl;
		for (size_t x = 0; x < av.size(); ++x)
			std::cerr << av[x] << " ";
		std::cout << std::endl;
		exit(-2);
	}

	this->cmd.push_back(av);
}

bool		Avm::isValidValue( stringV argv ) const
{
	int						i;
	static const char		*inst[] = {
		"push", "assert"
	};
	static const char		*val[] = {
		"int8\\([-]?[0-9]+\\)", "int16\\([-]?[0-9]+\\)", "int32\\([-]?[0-9]+\\)", "float\\([-]?[0-9]+\\.[0-9]+\\)", "double\\([-]?[0-9]+\\.[0-9]+\\)"
	};

	if (argv.size() != 2 )
		return (false);

	for (i = 0; i < 2; ++i)
	{
		if ( !strcmp(inst[i], argv[0].c_str()) )
			break;
	}
	if (i == 2)
		return (false);

	for (i = 0; i < 5; ++i)
	{
		if ( std::regex_match(argv[1], std::regex( val[i] ) ) )
			return (true);
	}

	return (false);
}

bool		Avm::isValidInst( stringV argv ) const
{
	static const char		*inst[] = {
		"pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"
	};

	if (argv.size() == 2 )
		return (this->isValidValue(argv));
	else if (argv.size() != 1)
		return (false);

	for (int i = 0; i < 9; ++i)
	{
		if ( !strcmp(inst[i], argv[0].c_str()) )
			return (true);
	}

	return (false);
}
