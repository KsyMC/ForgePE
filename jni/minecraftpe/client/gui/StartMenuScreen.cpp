#include <string>
#include <vector>
#include <memory>

#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/gui/ImageWithBackground.h"
#include "minecraftpe/client/gui/ServerManagerOptionScreen.h"
#include "Substrate.h"

using namespace Touch;

using std::string;
using std::vector;

StartMenuScreen::InitReal StartMenuScreen::init_real = NULL;
StartMenuScreen::SetupPositionsReal StartMenuScreen::setupPositions_real = NULL;
StartMenuScreen::ButtonClickedReal StartMenuScreen::buttonClicked_real = NULL;
TButton *StartMenuScreen::_optionSMButton = NULL;

void StartMenuScreen::initHooks(void *handle) {
	MSHookFunction((void *) &StartMenuScreen::init,				(void *) &StartMenuScreen::init_hook,			(void **) &StartMenuScreen::init_real);
	MSHookFunction((void *) &StartMenuScreen::setupPositions,	(void *) &StartMenuScreen::setupPositions_hook,	(void **) &StartMenuScreen::setupPositions_real);
	MSHookFunction((void *) &StartMenuScreen::buttonClicked,	(void *) &StartMenuScreen::buttonClicked_hook,	(void **) &StartMenuScreen::buttonClicked_real);
}

void StartMenuScreen::init_hook() {
	if(!_optionSMButton) {
		_optionSMButton = new TButton(0, "SM", NULL, false);
		_optionSMButton->init(_minecraftClient);
	}
	_vecBtn.push_back(_optionSMButton);

	StartMenuScreen::init_real(this);
}

void StartMenuScreen::setupPositions_hook() {
	StartMenuScreen::setupPositions_real(this);

	ImageWithBackground *optionButton = _optionButton;

	_optionSMButton->_x = optionButton->_x;
	_optionSMButton->_y = optionButton->_y - optionButton->_height - 10;
	_optionSMButton->_width = optionButton->_width;
	_optionSMButton->_height = optionButton->_height;
}

void StartMenuScreen::buttonClicked_hook(Button *button) {
	StartMenuScreen::buttonClicked_real(this, button);

	if(button->_buttonId == _optionSMButton->_buttonId) {
		_minecraftClient->setScreen(new ServerManagerOptionScreen());
	}
}
