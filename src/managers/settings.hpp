#ifndef settings_h
#define settings_h

class settings {
public:
	static bool getRemovePauses();

	static bool getShortText();

	static std::string getHighestConvert();

	static std::string getInfoLayerPosition();

	static bool getStopCompletion();
};
#endif // !settings_h