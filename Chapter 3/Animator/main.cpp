#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Animator.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "AssetManager");
	AssetManager manager;

	sf::Vector2i spriteSize(110, 284);
	sf::Sprite sprite;
	Animator animator(sprite);
	//Idle animation with 8 frames @ 1 sec looping
	auto& idleAnimation = animator.CreateAnimation("Idle", "stones.png", sf::seconds(1), true);
	idleAnimation.AddFrames(sf::Vector2i(0, 0), spriteSize, 8);

	//IdleShort animation with 8 frames @ 0.5 sec looping
	auto& idleAnimationShort = animator.CreateAnimation("IdleShort", "stones.png", sf::seconds(0.00001f), true);
	idleAnimationShort.AddFrames(sf::Vector2i(0, 0), spriteSize, 8);

	//IdleSmall animation with 5 frames @ 1.5 sec looping
	auto& idleAnimationSmall = animator.CreateAnimation("IdleSmall", "stones.png", sf::seconds(1.5f), true);
	//Adding frames multiple times from different locations
	idleAnimationSmall.AddFrames(sf::Vector2i(110 * 2, 0), spriteSize, 3);
	idleAnimationSmall.AddFrames(sf::Vector2i(110 * 2, 0), spriteSize, 2);

	//IdleOnce animation with 8 frames @ 0.5 sec not looping
	auto& idleAnimationOnce = animator.CreateAnimation("IdleOnce", "stones.png", sf::seconds(0.5f), false);
	idleAnimationOnce.AddFrames(sf::Vector2i(0, 0), spriteSize, 8);


	sf::Clock clock;
	while (window.isOpen())
	{
		//Returns the elapsed time and restarts the clock
		sf::Time deltaTime = clock.restart();

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::Key::Num1)
					animator.SwitchAnimation("Idle");
				else if (ev.key.code == sf::Keyboard::Key::Num2)
					animator.SwitchAnimation("IdleShort");
				else if (ev.key.code == sf::Keyboard::Key::Num3)
					animator.SwitchAnimation("IdleSmall");
				else if (ev.key.code == sf::Keyboard::Key::Num4)
					animator.SwitchAnimation("IdleOnce");
			}
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}

		animator.Update(deltaTime);

		window.clear(sf::Color::Black);

		window.draw(sprite);

		window.display();
	}

	//After main() returns, the manager is destroyed
	return 0;
}

