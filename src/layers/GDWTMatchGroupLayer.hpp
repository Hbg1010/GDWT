#pragma once

#include <Geode/Geode.hpp>
#include "../utils/data.hpp"

using namespace geode::prelude;

class GDWTMatchGroupLayer : public Popup {
    protected:
        bool init(const MatchGroup& _group);
    public:
        static GDWTMatchGroupLayer* create(const MatchGroup& _group);

        arc::Future<std::vector<scoreCalcFuture::Output>> testFunc(MatchesFuture::Output _matches);

        void show() override;

        MatchGroup group;

        async::TaskHolder<MatchesFuture::Output> l;

        async::TaskHolder<std::vector<scoreCalcFuture::Output>> scoresL;

        ScrollLayer* matchesListLayer;
        CCNode* alignmentNode;
};