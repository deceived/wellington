#include "sprite_component.hpp"

const std::string SpriteComponent::name_ = "SpriteComponent";



bool SpriteComponent::Init(pugi::xml_node data)
{
    return true;
}

void SpriteComponent::PostInit()
{
}
