//
// Created by Eryk on 04.01.2021.
//

#include "HUD.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include "Player.h"

using namespace Disappointment;

HUD::HUD()
{
	font.loadFromFile("res/fonts/HUD.ttf");

	text.setFont(font);
	text.setCharacterSize(32);
}

void HUD::update(Player const& player, sf::RenderTarget const& target)
{
	sf::Vector2f converted_screen_coords = target.mapPixelToCoords({ 10, 10 });

	text.setString(
			"Health: " + player.healthInPercentage() + '\n' +
			"Position: " + std::to_string(static_cast<int>(player.bodyBounds().left)) +
			" : " + std::to_string(static_cast<int>(player.bodyBounds().top)) + '\n' +
			"Magazine: " + std::to_string(player.bulletsLeft()) + '/' + std::to_string(player.magazineSize())
	);

	text.setPosition(converted_screen_coords);
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}

