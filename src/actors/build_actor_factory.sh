#!/bin/bash
[ -f actor_factory ] && rm actor_factory
g++ -std=c++11 -o actor_factory test_actor_factory.cpp actor_factory.cpp actor.cpp ai_component.cpp fight_component.cpp identity_component.cpp move_component.cpp order_component.cpp reaction_component.cpp sprite_component.cpp pugixml.cpp
[ -f actor_factory ] && ./actor_factory
