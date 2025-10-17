#include <Geode/Geode.hpp>


using namespace geode::prelude;


#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(MyLevelInfoLayer, LevelInfoLayer) {



	bool init(GJGameLevel * level, bool challenge) {

		if (!LevelInfoLayer::init(level, challenge)) {
			return false;
		}
		auto savedir = Mod::get()->getSaveDir();
		auto savedirstr = savedir.string();


		log::debug("Save Directory: {}", fmt::to_string(savedirstr));



		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyLevelInfoLayer::onMyButton)
		);

		auto menu = this->getChildByID("other-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);
		myButton->setContentSize({ 46.f, 47.5f });
		menu->ignoreAnchorPointForPosition(false);
		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show();
	}
};