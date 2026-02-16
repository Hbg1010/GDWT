#include "../hooks/MenuLayer.hpp"
#include "../layers/GDWTLayer.hpp"
#include "../utils/data.hpp"

bool GDWTMenuLayer::init() {
	if (!MenuLayer::init()) return false;

	async::spawn(data::getPlayersData());
	async::spawn(data::getTeamsData());
	async::spawn(data::getMatchesData());
	async::spawn(data::getMatchGroupsData());

	auto BMenu = this->getChildByID("bottom-menu");

    auto GDWTButtonSprite = CCSprite::create("GDTW-Button.png"_spr);
	auto GDWTButton = CCMenuItemSpriteExtra::create(
		GDWTButtonSprite,
		this,
		menu_selector(GDWTMenuLayer::onGDWTButton)
	);

	auto indecator = CCLabelBMFont::create(".", "bigFont.fnt");
    indecator->setColor({ 0, 255, 0 });
    indecator->setPositionY(12);
    indecator->setAlignment(CCTextAlignment::kCCTextAlignmentCenter);
    indecator->setVisible(data::getIsInMatch());
	indecator->setPosition({41, 56});
	indecator->setScale(1.5f);
    GDWTButton->addChild(indecator);

	BMenu->addChild(GDWTButton);

	GDWTButton->setID("gdwt-button");

	BMenu->updateLayout();

	return true;
}

void GDWTMenuLayer::onGDWTButton(CCObject*) {
	GDWTLayer::create()->open();
}

