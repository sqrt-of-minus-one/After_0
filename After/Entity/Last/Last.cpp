    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Last.cpp                    //
////////////////////////////////////////

#include "Last.h"
#include "../../System/Controls.h"

using sf::IntRect;
using sf::View;

Last::Last() : Entity(0, "last")
{
}

void Last::calculateStats()
{
}

void Last::deathDrop()
{
}

void Last::weak()
{
}

void Last::tick(const float delta)
{
	isWalking = true;
	if (Keyboard::isKeyPressed(S_Controls::forward))
	{
		if (Keyboard::isKeyPressed(S_Controls::right))
		{
			if (direction != FR)
			{
				direction = FR;
				IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_fr);
				sprite.setTextureRect(rect);
			}
		}
		else if (Keyboard::isKeyPressed(S_Controls::left))
		{
			if (direction != FL)
			{
				direction = FL;
				IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_fl);
				sprite.setTextureRect(rect);
			}
		}
		else if (direction != F)
		{
			direction = F;
			IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_f);
			sprite.setTextureRect(rect);
		}
	}
	else if (Keyboard::isKeyPressed(S_Controls::back))
	{
		if (Keyboard::isKeyPressed(S_Controls::right))
		{
			if (direction != BR)
			{
				direction = BR;
				IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_br);
				sprite.setTextureRect(rect);
			}
		}
		else if (Keyboard::isKeyPressed(S_Controls::left))
		{
			if (direction != BL)
			{
				direction = BL;
				IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_bl);
				sprite.setTextureRect(rect);
			}
		}
		else if (direction != B)
		{
			direction = B;
			IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_b);
			sprite.setTextureRect(rect);
		}
	}
	else if (Keyboard::isKeyPressed(S_Controls::right))
	{
		if (direction != R)
		{
			direction = R;
			IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_r);
			sprite.setTextureRect(rect);
		}
	}
	else if (Keyboard::isKeyPressed(S_Controls::left))
	{
		if (direction != L)
		{
			direction = L;
			IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_l);
			sprite.setTextureRect(rect);
		}
	}
	else
	{
		isWalking = false;
	}

	Entity::tick(delta);
}

void Last::getCenter(float& x, float& y)
{
	x = sprite.getPosition().x + entityData->width * WIDTH / 2;
	y = sprite.getPosition().y + entityData->height * HEIGHT / 2;
}