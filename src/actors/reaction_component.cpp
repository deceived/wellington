#include "reaction_component.hpp"

const std::string ReactionComponent::name_ = "ReactionComponent";


bool ReactionComponent::Init(Properties::ptr data)
{
    return true;
}

bool ReactionComponent::Init(Properties::pointer data)
{
    return true;
}

void ReactionComponent::PostInit()
{
}
