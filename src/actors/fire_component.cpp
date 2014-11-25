#include "fire_component.hpp"

const std::string FireComponent::name_ = "FireComponent";



bool FireComponent::Init(pugi::xml_node data)
{
    return true;
}

void FireComponent::PostInit()
{
}
