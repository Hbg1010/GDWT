#pragma once

#include <Geode/Geode.hpp>
#include "../utils/data.hpp"

using namespace geode::prelude;

class UserDisplay : public CCNode {
    protected:
        bool init(int accountID, bool withName);
    public:
        static UserDisplay* create(int accountID, bool withName = true);

        static UserDisplay* create(Host host, bool withName = true);

        static UserDisplay* create(PlayerData player, bool withName = true);

        SimplePlayer* player;
        LoadingCircle* IconLoadingC;
        CCLayer* loadingCLayer;

        std::string displayName = "";

        CCLabelBMFont* nameLabel = nullptr;
        CCNode* labelCont;

        int accID;

        bool lol;

        void userClicked(CCObject*);

        void onDInfoReceved(GDWTUserInfoFuture::Output out);

        void onPlayerInfoReceved(PlayerDataFuture::Output out);

        void updateNameLength();

        async::TaskHolder<GDWTUserInfoFuture::Output> Ulistener;

        async::TaskHolder<PlayerDataFuture::Output> Plistener;

        async::TaskHolder<TeamsFuture::Output> Tlistener;
};