#pragma once

#include <Geode/Geode.hpp>
#include "../utils/data.hpp"
#include <Geode/utils/web.hpp>
#include "../layers/GDWTMatchLevelCell.hpp"

using namespace geode::prelude;

class GDWTMatchLayer : public Popup, public LevelManagerDelegate {
    protected:
        bool init(const Match& _matchs);

        void onClose(cocos2d::CCObject*) override;
    public:
        static GDWTMatchLayer* create(const Match& _match);

        void show() override;

        void update(float delta) override;

        Match match;

        void ytClicked(CCObject*);
        void twitchClicked(CCObject*);

        ScrollLayer* hostsScrollLayer;
        ScrollLayer* coHostsScrollLayer;
        ScrollLayer* levelsListLayer;
        int scrollSwitch;

        void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1) override;
        void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1, int p2) override;

        void loadLevelsFailed(char const* p0) override;
        void loadLevelsFailed(char const* p0, int p1) override;

        std::vector<GDWTMatchLevelCell*> levelCells;

        async::TaskHolder<scoreCalcFuture::Output> overallScoresListener;
};