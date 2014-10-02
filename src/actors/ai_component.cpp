#include "ai_component.hpp"

const std::string AiComponent::name_ = "AiComponent";


bool AiComponent::Init(Properties::ptr data)
{
    return true;
}

bool AiComponent::Init(Properties::pointer data)
{
    return true;
}

void AiComponent::PostInit()
{
}
