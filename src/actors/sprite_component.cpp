#include "sprite_component.hpp"

const std::string SpriteComponent::name_ = "SpriteComponent";


bool SpriteComponent::Init(Properties::ptr data)
{
    return true;
}

bool SpriteComponent::Init(Properties::pointer data)
{
    return true;
}

void SpriteComponent::PostInit()
{
}
