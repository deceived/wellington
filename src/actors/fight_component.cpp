#include "fight_component.hpp"

const std::string FightComponent::name_ = "FightComponent";


bool FightComponent::Init( pugi::xml_node data )
{
    return true;
}

void FightComponent::PostInit()
{
}
