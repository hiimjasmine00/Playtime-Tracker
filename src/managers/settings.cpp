#include "./settings.hpp"

using namespace geode::prelude;


bool settings::getRemovePauses() {
	return Mod::get()->getSettingValue<bool>("remove-pauses");
}

bool settings::getShortText() {
	return Mod::get()->getSettingValue<bool>("short-text");
}

std::string settings::getHighestConvert() {
	return Mod::get()->getSettingValue<std::string>("highest-convert");
}

std::string settings::getInfoLayerPosition() {
	return Mod::get()->getSettingValue<std::string>("infoLayer-position");
}

bool settings::getStopOnCompletion() {
	return Mod::get()->getSettingValue<bool>("stop-completion");
}

std::string settings::getTimeFormat() {
	return Mod::get()->getSettingValue<std::string>("time-format");
}

bool settings::getUseCustomTimeFormat() {
	return Mod::get()->getSettingValue<bool>("use-custom-time-format");
}

std::string settings::getCustomTimeFormat() {
	return Mod::get()->getSettingValue<std::string>("custom-time-format");
}

bool settings::getDisableDeletionPopup() {
	return Mod::get()->getSettingValue<bool>("disable-deletion-popup");
}