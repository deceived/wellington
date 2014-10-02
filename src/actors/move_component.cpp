#include "move_component.hpp"

const std::string MoveComponent::name_ = "MoveComponent";


bool MoveComponent::Init(Properties::ptr data)
{
    return true;
}

bool MoveComponent::Init(Properties::pointer data)
{
    return true;
}

void MoveComponent::PostInit()
{
}
