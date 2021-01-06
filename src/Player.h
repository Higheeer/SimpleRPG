//
// Created by Eryk on 20.10.2020.
//

#ifndef DISAPPOINTMENT_PLAYER_H
#define DISAPPOINTMENT_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#include "Weapons/Weapon.h"

namespace Disappointment
{
	class Player : public sf::Drawable
	{
	public:
		Player(sf::Vector2f const& position, sf::Texture const& texture, sf::RenderWindow& window);

		void input(float delta_time);
		void event(sf::Event const& event);
		void update(float delta_time, std::vector<Enemy>& enemy);

		void hit(unsigned short int value);
		bool isDead() const;

		sf::FloatRect bodyBounds() const;
		std::string healthInPrecentage() const;

	private:
		void move(float delta_time);
		void rotateToMouse();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		short int max_health;
		short int health;

		std::unique_ptr<Weapon> weapon;

		sf::RectangleShape body;
		sf::RenderWindow& window;
	};

	float normalize(float value);
}
#endif //DISAPPOINTMENT_PLAYER_H
