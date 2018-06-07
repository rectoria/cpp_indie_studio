/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BombEntity.hpp
*/

#ifndef BOMBERMAN_BOMBENTITY_HPP
#define BOMBERMAN_BOMBENTITY_HPP


#include "../../../include/Game/AEntity.hpp"

class BombEntity : public AEntity {
public:
	BombEntity(int x = 0, int y = 0);

	bool hasExploded() const;
};


#endif /* !BOMBERMAN_BOMBENTITY_HPP */
