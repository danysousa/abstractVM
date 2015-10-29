#include <Factory.hpp>

Factory::Factory()
{

}

Factory::Factory(Factory const & cpy)
{
	*this = cpy;
}

Factory::~Factory()
{
}

Factory	Factory::operator=( Factory const & cpy )
{
	return (*this);
}

/*
** METHODS
*/

