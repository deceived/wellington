#include "ai_component.hpp"

const std::string AiComponent::name_ = "AiComponent";


bool AiComponent::Init( pugi::xml_node data )
{
    return true;
}

void AiComponent::PostInit()
{
}
