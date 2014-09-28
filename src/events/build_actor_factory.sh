#!/bin/bash
[ -f actor_factory ] && rm actor_factory
g++ -std=c++11 -o actor_factory test_actor_factory.cpp actor_factory.cpp actor.cpp 
[ -f actor_factory ] && ./actor_factory
