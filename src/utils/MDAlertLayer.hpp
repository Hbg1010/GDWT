#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class MDAlertLayer : public Popup {
    protected:
        bool init(const std::string& title, const std::string& description, const std::string& btn1Name, const std::function<void(bool)>& callback, const std::string& btn2Name);

    public:
        static MDAlertLayer* create(const std::string& title, const std::string& description, const std::string& btn1Name = "OK", const std::function<void(bool)>& callback = NULL, const std::string& btn2Name = "NULL");

        void show();

    private:
        std::function<void(bool)> callback;

        CCMenuItemSpriteExtra* btn1 = nullptr;
        CCMenuItemSpriteExtra* btn2 = nullptr;
        void OnBtnClicked(CCObject* sender);

        void sendResult(bool res);
};