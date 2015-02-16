#pragma once

class Screen;

class ScreenChooser {
public:
	Screen *createScreen(ScreenId);
	void setScreen(ScreenId);
};
