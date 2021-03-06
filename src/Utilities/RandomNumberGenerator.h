//
// Created by Eryk on 03.11.2020.
//

#ifndef DISAPPOINTMENT_SRC_RANDOMNUMBERGENERATOR_H_
#define DISAPPOINTMENT_SRC_RANDOMNUMBERGENERATOR_H_

#include <random>

namespace Disappointment
{
	class RandomNumberGenerator
	{
	public:
		RandomNumberGenerator() = delete;

	public:
		[[nodiscard]] static unsigned int getNumber(unsigned int const& min, unsigned int const& max);

		static void setSeed(unsigned int const& seed);

	private:
		static std::random_device seedGenerator;
		static std::mt19937_64 engine;
	};
}
#endif //DISAPPOINTMENT_SRC_RANDOMNUMBERGENERATOR_H_
