#include "fight_component.hpp"

const std::string FightComponent::name_ = "FightComponent";


bool FightComponent::Init(Properties::ptr data)
{
    return true;
}

bool FightComponent::Init(Properties::pointer data)
{
    return true;
}

void FightComponent::PostInit()
{
}
