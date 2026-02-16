#pragma once

#include <Geode/Geode.hpp>
#include "../utils/data.hpp"

using namespace geode::prelude;

class GDWTTeamLayer : public Popup {
    protected:
        bool init(const Team& _team);
    public:
        static GDWTTeamLayer* create(const Team& _team);

        void show() override;

        Team team;

        ScrollLayer* playersScroll;
        ScrollLayer* inactiveScroll;
};