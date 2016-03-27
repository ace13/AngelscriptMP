#pragma once

#include <cstdint>

namespace sf
{
	class RenderWindow;
}

namespace Graphics
{

class Voxel;

namespace Renderer
{

class IRenderer
{
public:
	IRenderer(sf::RenderWindow& target) : mRT(target) { }

	virtual ~IRenderer() = default;

	virtual bool isAvailable() const = 0;

	virtual void beginRender() = 0;
	virtual void endRender() = 0;

	virtual void render(const Voxel* voxels, uint32_t count) = 0;

protected:
	sf::RenderWindow& getRenderWindow() { return mRT; }
	const sf::RenderWindow& getRenderWindow() const { return mRT; }

private:
	sf::RenderWindow& mRT;
};

}
}
