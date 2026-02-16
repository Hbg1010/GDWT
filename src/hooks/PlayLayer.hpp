#include <Geode/Geode.hpp>
#include "../utils/data.hpp"

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>
class $modify(GDWTPlayLayer, PlayLayer) {
    struct Fields {
        bool hasRespawned = false;
        async::TaskHolder<Result<>> listener;
        float currentRunStartprecent;
        geode::Notification* notifCBF = nullptr;
    };

    void destroyPlayer(PlayerObject* p0, GameObject* p1);

    void resetLevel();
    
    void levelComplete();

    void sendProgressMessage(int precent, GJGameLevel* level, int combo);

    arc::Future<Result<>> sendMessagesFuture(DiscordMessage message, int precent);
};