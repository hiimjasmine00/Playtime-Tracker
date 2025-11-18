#include <ctime>
#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

#include <cvolton.level-id-api/include/EditorIDs.hpp>

#include "../managers/data.hpp"
#include "../managers/settings.hpp"

using namespace geode::prelude;

class $modify(PTEditLevelLayer, EditLevelLayer) {
	bool init(GJGameLevel * level) {
		if (!(EditLevelLayer::init(level))) {
			return false;
		}



		auto sprite = CCSprite::create("playtimeButton.png"_spr);
		auto playtimeButton = CCMenuItemSpriteExtra::create(
			sprite,
			this,
			menu_selector(PTEditLevelLayer::onPlaytimeButton)
		);

		sprite->setScale(0.75f);

		auto infoButtonMenu = this->getChildByID("info-button-menu");

		playtimeButton->setID("playtime-tracker-button");
		

		playtimeButton->setUserObject(CCString::create("Editor-" + std::to_string(EditorIDs::getID(level))));
		
		
		playtimeButton->setZOrder(1);

		float x = 34.5f;
		float y = infoButtonMenu->getChildByID("settings-button")->getPositionY();

		playtimeButton->setPosition({ x, y });

		infoButtonMenu->addChild(playtimeButton);
		infoButtonMenu->updateLayout();

		return true;
	}

	void onPlaytimeButton(CCObject* sender) {
		auto obj = static_cast<CCNode*>(sender)->getUserObject();

		std::string str = static_cast<CCString*>(obj)->getCString();
		auto playtime = data::getPlaytimeRaw(str);


		FLAlertLayer::create(
			"Playtime Tracker",
			CCString::create(data::formattedPlaytime(playtime))->getCString(),
			"close"
		)->show();
	}
};