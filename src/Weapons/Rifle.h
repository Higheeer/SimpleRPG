//
// Created by Eryk on 23.12.2020.
//

#ifndef DISAPPOINTMENT_RIFLE_H
#define DISAPPOINTMENT_RIFLE_H

#include <string>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Weapon.h"
#include "Bullet.h"

namespace Disappointment
{
	class Rifle : public Weapon
	{
	public:
		explicit Rifle(sf::RenderWindow& window);

		void shoot(float delta_time, sf::Vector2f const& player_position) override;
		void reload() override;
		void update(float delta_time, std::vector<Enemy>& enemies) override;

		[[nodiscard]] unsigned short int bulletsLeft() const override;
		[[nodiscard]] unsigned short int magazineSize() const override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::RenderWindow& window;

		unsigned int magazine_size;
		unsigned int bullets_in_magazine;

		std::vector<Bullet> active_bullets;

		sf::RectangleShape body;
	};
}

#endif //DISAPPOINTMENT_RIFLE_H
