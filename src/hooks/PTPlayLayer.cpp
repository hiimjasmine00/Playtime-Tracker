#include <ctime>
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include "../managers/data.hpp"

using namespace geode::prelude;


class $modify(PTPlayLayer, PlayLayer) {

	bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects) {
		if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
			return false;
		}
		time_t timestamp;
		log::debug("STARTED LEVEL AT: {}", fmt::to_string(time(&timestamp)));

		return true;
	}


};