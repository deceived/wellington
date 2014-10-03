#include "reaction_component.hpp"

const std::string ReactionComponent::name_ = "ReactionComponent";



bool ReactionComponent::Init( pugi::xml_node data )
{
    return true;
}

void ReactionComponent::PostInit()
{
}
