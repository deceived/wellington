#include "actor.hpp"
#include "actor_component.hpp"

Actor::Actor(Actor::Id id)
{
    actorId_ = id;
//    type_ = "Unknown";
}

Actor::~Actor()
{
}

bool Actor::Init( Properties::ptr data )
{
//	m_type = pData->Attribute("type");
//	m_resource = pData->Attribute("resource");
    return true;
}

void Actor::PostInit(void)
{
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->PostInit();
    }
}

void Actor::Destroy(void)
{
    components_.clear();
}

void Actor::Update( int deltaMs )
{
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->Update( deltaMs );
    }
}

std::string Actor::ToXML()
{
#if 0
    TiXmlDocument outDoc;

    TiXmlElement* pActorElement = GCC_NEW TiXmlElement("Actor");
    pActorElement->SetAttribute("type", m_type.c_str());
	pActorElement->SetAttribute("resource", m_resource.c_str());

    for (auto it = m_components.begin(); it != m_components.end(); ++it)
    {
        StrongActorComponentPtr pComponent = it->second;
        TiXmlElement* pComponentElement = pComponent->VGenerateXml();
        pActorElement->LinkEndChild(pComponentElement);
    }

    outDoc.LinkEndChild(pActorElement);
	TiXmlPrinter printer;
	outDoc.Accept(&printer);

	return printer.CStr();
#endif
    return std::string();
}


void Actor::AddComponent( ActorComponent::ptr component )
{
    std::pair<ActorComponents::iterator, bool> success = components_.insert( std::make_pair( component->GetId(), component ) );
}

