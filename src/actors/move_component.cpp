#include "move_component.hpp"

extern Log logger;

const std::string MoveComponent::name_ = "MoveComponent";



bool MoveComponent::Init(pugi::xml_node data)
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
    return true;
    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
    }
}

void MoveComponent::PostInit()
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
}
