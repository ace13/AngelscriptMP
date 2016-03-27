#pragma once

#include "Transformable3D.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/InputStream.hpp>

#include <vector>

namespace std
{
	class string;
}

namespace Graphics
{

class Voxel : public Transformable3D//, public Drawable3D
{
public:
	Voxel();

	bool loadFromFile(const std::string& file);
	bool loadFromStream(sf::InputStream& stream);

private:
#pragma pack(push, 1)
	struct VoxelData
	{
		sf::Vector3f Position;
		sf::Color Color;
	};
#pragma pack(pop)

	std::vector<VoxelData> mData;
};

}
