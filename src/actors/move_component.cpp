#include "move_component.hpp"

const std::string MoveComponent::name_ = "MoveComponent";



bool MoveComponent::Init(pugi::xml_node data)
{
    return true;
}

void MoveComponent::PostInit()
{
}
