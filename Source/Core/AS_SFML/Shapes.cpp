#include "Shared.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace
{
	template<typename T>
	void createShape(void* mem)
	{
		new (mem) T();
	}
	template<typename T, typename... Args>
	void createShapeData(void* mem, Args... args)
	{
		new (mem) T(args...);
	}
	template<typename T>
	void destroyShape(T* mem)
	{
		mem->~T();
	}
}

bool as::priv::RegCircleShape(asIScriptEngine* eng)
{
	AS_ASSERT(eng->SetDefaultNamespace("sf"));

	AS_ASSERT(eng->RegisterObjectType("CircleShape", sizeof(sf::CircleShape), asGetTypeTraits<sf::CircleShape>()));
	AS_ASSERT(eng->RegisterObjectBehaviour("CircleShape", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(createShape<sf::CircleShape>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("CircleShape", asBEHAVE_CONSTRUCT, "void f(float)", asFunctionPtr(createShapeData<sf::CircleShape,float>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("CircleShape", asBEHAVE_CONSTRUCT, "void f(float,uint)", asFunctionPtr(createShapeData<sf::CircleShape,float,size_t>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("CircleShape", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(destroyShape<sf::CircleShape>), asCALL_CDECL_OBJFIRST));

	if (!RegisterDrawable<sf::CircleShape>(eng, "CircleShape")) return false;
	if (!RegisterShape<sf::CircleShape>(eng, "CircleShape")) return false;
	if (!RegisterTransformable<sf::CircleShape>(eng, "CircleShape")) return false;

	AS_ASSERT(eng->RegisterObjectMethod("CircleShape", "void set_PointCount(uint)", asMETHOD(sf::CircleShape, setPointCount), asCALL_THISCALL));
	AS_ASSERT(eng->RegisterObjectMethod("CircleShape", "float get_Radius() const", asMETHOD(sf::CircleShape, getRadius), asCALL_THISCALL));
	AS_ASSERT(eng->RegisterObjectMethod("CircleShape", "void set_Radius(float)", asMETHOD(sf::CircleShape, setRadius), asCALL_THISCALL));

	AS_ASSERT(eng->SetDefaultNamespace(""));

	return true;
}

bool as::priv::RegConvexShape(asIScriptEngine* eng)
{
	AS_ASSERT(eng->SetDefaultNamespace("sf"));

	AS_ASSERT(eng->RegisterObjectType("ConvexShape", sizeof(sf::ConvexShape), asGetTypeTraits<sf::ConvexShape>()));
	AS_ASSERT(eng->RegisterObjectBehaviour("ConvexShape", asBEHAVE_CONSTRUCT, "void f(uint)", asFunctionPtr(createShapeData<sf::ConvexShape, size_t>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("ConvexShape", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(destroyShape<sf::ConvexShape>), asCALL_CDECL_OBJFIRST));

	if (!RegisterDrawable<sf::ConvexShape>(eng, "ConvexShape")) return false;
	if (!RegisterShape<sf::ConvexShape>(eng, "ConvexShape")) return false;
	if (!RegisterTransformable<sf::ConvexShape>(eng, "ConvexShape")) return false;

	AS_ASSERT(eng->RegisterObjectMethod("ConvexShape", "void set_PointCount(uint)", asMETHOD(sf::ConvexShape, setPointCount), asCALL_THISCALL));
	AS_ASSERT(eng->RegisterObjectMethod("ConvexShape", "void set_opIndex(uint,const Vec2&in)", asMETHOD(sf::ConvexShape, setPoint), asCALL_THISCALL));

	AS_ASSERT(eng->SetDefaultNamespace(""));

	return true;
}

bool as::priv::RegRectangleShape(asIScriptEngine* eng)
{
	AS_ASSERT(eng->SetDefaultNamespace("sf"));

	AS_ASSERT(eng->RegisterObjectType("RectangleShape", sizeof(sf::RectangleShape), asGetTypeTraits<sf::RectangleShape>()));
	AS_ASSERT(eng->RegisterObjectBehaviour("RectangleShape", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(createShape<sf::RectangleShape>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("RectangleShape", asBEHAVE_CONSTRUCT, "void f(const Vec2&in)", asFunctionPtr(createShapeData<sf::RectangleShape,const sf::Vector2f&>), asCALL_CDECL_OBJFIRST));
	AS_ASSERT(eng->RegisterObjectBehaviour("RectangleShape", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(destroyShape<sf::RectangleShape>), asCALL_CDECL_OBJFIRST));

	if (!RegisterDrawable<sf::RectangleShape>(eng, "RectangleShape")) return false;
	if (!RegisterShape<sf::RectangleShape>(eng, "RectangleShape")) return false;
	if (!RegisterTransformable<sf::RectangleShape>(eng, "RectangleShape")) return false;

	AS_ASSERT(eng->RegisterObjectMethod("RectangleShape", "const Vec2& get_Size() const", asMETHOD(sf::RectangleShape, getSize), asCALL_THISCALL));
	AS_ASSERT(eng->RegisterObjectMethod("RectangleShape", "void set_Size(const Vec2&in)", asMETHOD(sf::RectangleShape, setSize), asCALL_THISCALL));

	AS_ASSERT(eng->SetDefaultNamespace(""));

	return true;
}
