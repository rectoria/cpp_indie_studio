/*
** EPITECH PROJECT, 2018
** indie
** File description:
** indie
*/

#include "../../include/Game/AEntity.hpp"

AEntity::AEntity(const std::string &type)
: ATrackable(), _type(type), _origin(-200, 200, -100), _node(), _stackable(true)
{
}

void AEntity::update(EntitiesMap *)
{
}

void AEntity::updateRender()
{
	auto nodePos = _node->getPosition();
	auto pos = calculateConvertedPosition();
	auto origin = getOrigin();

	if (origin.X + pos.X != nodePos.X ||
	    origin.Z + pos.Y != nodePos.Z) {
		nodePos.Y = origin.Y;
		nodePos.X = origin.X + pos.X;
		nodePos.Z = origin.Z + pos.Y;
		_node->setPosition(nodePos);
	}
}

// region Save & load

void AEntity::dump(std::ostream &s) const
{
	struct AEntity::serialize ser = {_position.X, _position.Y};
	auto se = std::unique_ptr<char>(new char[sizeof(ser)]);
	memcpy(se.get(), &ser, sizeof(ser));
	s << _type;
	s.write("\0", 1);
	s.write(se.get(), sizeof(ser));
}

void AEntity::load(std::istream &s)
{
	struct AEntity::serialize ser {};
	auto se = std::unique_ptr<char>(new char[sizeof(ser)]);
	s.read(se.get(), sizeof(ser));
	memcpy(&ser, se.get(), sizeof(ser));
	setPosition({ser.x, ser.y});
}

std::ostream &operator<<(std::ostream &s, const AEntity &e)
{
	e.dump(s);
	return s;
}

AEntity &operator>>(std::istream &s, AEntity &e)
{
	e.load(s);
	return e;
}

// endregion

void AEntity::collide(AEntity &)
{
}

const irr::core::vector3df &AEntity::getOrigin() const
{
	return _origin;
}

bool AEntity::isStackable() const
{
	return _stackable;
}

irr::core::vector2d<float> AEntity::calculateConvertedPosition() const
{
	auto pos = getPosition();
	irr::core::vector2d<float> converted {};
	converted.X = static_cast<float>(pos.X * ENTITY_SIZE_X);
	converted.Y = static_cast<float>(pos.Y * ENTITY_SIZE_Y);
	return converted;
}
