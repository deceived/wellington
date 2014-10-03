#include "ai_component.hpp"

const std::string AiComponent::name_ = "AiComponent";


bool AiComponent::Init( pugi::xml_node data )
{
    std::cout << "name()" << data.name() << std::endl;
    return true;
}

void AiComponent::PostInit()
{
}
