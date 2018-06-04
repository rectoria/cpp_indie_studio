/*
** EPITECH PROJECT, 2018
** indie
** File description:
** indie
*/

#include "../../include/Game/EntityFactory.hpp"

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{
}

std::unique_ptr<AEntity> EntityFactory::createEntity(const std::string &name)
{
	if (_fac.find(name) != _fac.end()) {
		return _fac.at(name)();
	} else
		throw std::runtime_error("entity not implemented yet");
}