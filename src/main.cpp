#include <ctime>
#include <Geode/Geode.hpp>

#include "./managers/data.hpp"

using namespace geode::prelude;


$execute {
	time_t timestamp;
	log::debug("EXECUTED AT: {}", fmt::to_string(time(&timestamp)));
};

$on_mod (Loaded){
	time_t timestamp;
	log::debug("LOADED MOD AT: {}", fmt::to_string(time(&timestamp)));
};