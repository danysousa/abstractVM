#include <Avm.hpp>
#include <iostream>

int		main(int argc, char *argv[])
{
	Avm		*avm;

	if (argc != 2)
	{
		std::cerr << "Usage : ./avm <filename>" << std::endl;
		return (-1);
	}
	avm = new Avm(argv[1]);
	return 0;
}