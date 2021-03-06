/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BKeyboardController.hpp
*/

#ifndef BOMBERMAN_KEYBOARDCONTROLLER_HPP
#define BOMBERMAN_KEYBOARDCONTROLLER_HPP

#include <unordered_map>
#include <map>
#include <list>
#include "Controllable.hpp"

class BKeyboardController : public AController {
public:
	explicit BKeyboardController(size_t id);
	virtual ~BKeyboardController();
	void registerBind(irr::EKEY_CODE code, ControlName c, ControlType t);
	void unregisterBind(irr::EKEY_CODE code, ControlType t);
	void updateInputs(EntitiesMap *) override;
	ControllerType getType() const override;

	struct KeyMap {
		irr::EKEY_CODE key;
		ControlName control;
		ControlType type;
	};
private:
	std::unordered_map<irr::EKEY_CODE, ControlName>
	&_getBinds(ControlType t);

	size_t _id;
	std::unordered_map<irr::EKEY_CODE, ControlName> _bindsDown;
	std::unordered_map<irr::EKEY_CODE, ControlName> _bindsPressed;
	std::unordered_map<irr::EKEY_CODE, ControlName> _bindsReleased;
	std::unordered_map<irr::EKEY_CODE, bool> _isKeyDown;
	std::unordered_map<irr::EKEY_CODE, bool> _isKeyPressed;
	std::unordered_map<irr::EKEY_CODE, bool> _isKeyRelease;
	static const std::map<unsigned int, std::list<KeyMap>> _keyMap;
};


#endif /* !BOMBERMAN_KEYBOARDCONTROLLER_HPP */
