#include <string>
#include <vector>
#include <cstdlib>
#include <memory>

#include "minecraftpe/util/Util.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/TButton.h"
#include "minecraftpe/client/gui/THeader.h"
#include "minecraftpe/client/gui/TextBox.h"
#include "minecraftpe/client/gui/Label.h"
#include "minecraftpe/client/gui/IntRectangle.h"
#include "minecraftpe/client/gui/NinePatchLayer.h"
#include "minecraftpe/client/gui/StartMenuScreen.h"
#include "minecraftpe/client/gui/ServerManagerOptionScreen.h"
#include "minecraftpe/client/renderer/Tessellator.h"
#include "minecraftpe/client/renderer/texture/NinePatchFactory.h"

using namespace Touch;

using std::string;
using std::vector;

extern string _customServerName;
extern int _port;
extern int _maxPlayers;

void _saveData();

ServerManagerOptionScreen::ServerManagerOptionScreen() {
	_titleHeader = NULL;
	_nameLabel = NULL;
	_portLabel = NULL;
	_maxPlayersLabel = NULL;
	_nameTextBox = NULL;
	_portTextbox = NULL;
	_maxPlayersTextBox = NULL;
	_backButton = NULL;
	_saveButton = NULL;
	_backgroundLayer = NULL;
}

ServerManagerOptionScreen::~ServerManagerOptionScreen() {
	delete _titleHeader;
	delete _nameLabel;
	delete _portLabel;
	delete _maxPlayersLabel;
	delete _nameTextBox;
	delete _portTextbox;
	delete _maxPlayersTextBox;
	delete _backButton;
	delete _saveButton;
	delete _backgroundLayer;
}

void ServerManagerOptionScreen::render(int i1, int i2, float f1) {
	if(supppressedBySubWindow()) {
		renderBackground(0);
	} else {
		renderMenuBackground(f1);
		_backgroundLayer->draw(Tessellator::instance, _backgroundLayer->_x, _backgroundLayer->_y);
		_screenRenderer.drawString(_minecraftClient->_font, "로컬 서버의 옵션을 수정합니다.", (_width / 2) + 10, _titleHeader->_height + 10, Color::WHITE);
	}

	Screen::render(i1, i2, f1);
}

void ServerManagerOptionScreen::init() {
	_titleHeader = new THeader(0, "ServerManager - Options");

	_nameLabel = new Label("Server Name", _minecraftClient, Color::WHITE, 0, 0, 0, true);
	_portLabel = new Label("Port", _minecraftClient, Color::WHITE, 0, 0, 0, true);
	_maxPlayersLabel = new Label("Max Players", _minecraftClient, Color::WHITE, 0, 0, 0, true);

	_nameTextBox = new TextBox(_minecraftClient, "Server Name", 0, TextBox::extendedAcsii, strlen(TextBox::extendedAcsii), this, &Screen::onTextBoxUpdated, 0);
	_nameTextBox->setText(_customServerName);

	_portTextbox = new TextBox(_minecraftClient, "Port", 0, TextBox::extendedAcsii, strlen(TextBox::extendedAcsii), this, &Screen::onTextBoxUpdated, 0);
	_portTextbox->setText(Util::toString(_port));

	_maxPlayersTextBox = new TextBox(_minecraftClient, "Max Players", 0, TextBox::extendedAcsii, strlen(TextBox::extendedAcsii), this, &Screen::onTextBoxUpdated, 0);
	_maxPlayersTextBox->setText(Util::toString(_maxPlayers));

	_backButton = new TButton(0, "Back", NULL, false);
	_saveButton = new TButton(1, "Save", NULL, false);

	_backButton->init(_minecraftClient);
	_saveButton->init(_minecraftClient);

	_vecGui2E.push_back(_titleHeader);
	_vecGui2E.push_back(_nameLabel);
	_vecGui2E.push_back(_portLabel);
	_vecGui2E.push_back(_maxPlayersLabel);
	_vecGui2E.push_back(_nameTextBox);
	_vecGui2E.push_back(_portTextbox);
	_vecGui2E.push_back(_maxPlayersTextBox);
	_vecBtn.push_back(_backButton);
	_vecBtn.push_back(_saveButton);

	IntRectangle rectangle = {34, 43, 14, 14};

	NinePatchFactory factory(_minecraftClient->_textures, "gui/spritesheet.png");
	_backgroundLayer = factory.createSymmetrical(rectangle, 3, 3, 32.0f, 32.0f);
}

void ServerManagerOptionScreen::setupPositions() {
	int leftSpace = 10;
	int textboxWidth = (_width / 2) - leftSpace - 10;

	_titleHeader->_width = _width;

	_nameLabel->_x = leftSpace;
	_nameLabel->_y = _titleHeader->_height + 10;

	_nameTextBox->_x = leftSpace;
	_nameTextBox->_y = _nameLabel->_y + _portLabel->_height;
	_nameTextBox->_width = textboxWidth;

	_portLabel->_x = leftSpace;
	_portLabel->_y = _nameTextBox->_y + _nameTextBox->_height + 5;

	_portTextbox->_x = leftSpace;
	_portTextbox->_y = _portLabel->_y + _portLabel->_height;
	_portTextbox->_width = textboxWidth;

	_maxPlayersLabel->_x = leftSpace;
	_maxPlayersLabel->_y = _portTextbox->_y + _portTextbox->_height + 5;

	_maxPlayersTextBox->_x = leftSpace;
	_maxPlayersTextBox->_y = _maxPlayersLabel->_y + _portLabel->_height;
	_maxPlayersTextBox->_width = textboxWidth;

	_backButton->_x = 4;
	_backButton->_y = 4;
	_backButton->_width = 38;
	_backButton->_height = 18;

	_saveButton->_x = (_width - (_width / 4)) - (_saveButton->_width / 2) - 10;
	_saveButton->_y = (_height / 2) - (_saveButton->_height / 2);

	_backgroundLayer->_x = 5;
	_backgroundLayer->_y = _titleHeader->_height + 5;
	_backgroundLayer->setSize(_width - 10, _height - _titleHeader->_height - 10);
}

bool ServerManagerOptionScreen::handleBackEvent(bool b1) {
	if(!b1) {
		bool screenClose = true;

		for(std::vector<GuiElement *>::size_type i = 0; i < _vecGui2E.size(); i++) {
			if(_vecGui2E[i]->suppressOtherGUI()) {
				screenClose = false;
				_vecGui2E[i]->backPressed(_minecraftClient, false);
			}
		}

		if(screenClose) {
			closeScreen();
		}
	}

	return true;
}

void ServerManagerOptionScreen::buttonClicked(Button *button) {
	if(button->_buttonId == _saveButton->_buttonId) {
		_customServerName = _nameTextBox->_text;
		_maxPlayers = strtol(_maxPlayersTextBox->_text.c_str(), NULL, 10);
		_port = strtol(_portTextbox->_text.c_str(), NULL, 10);
		_saveData();
	}

	closeScreen();
}

void ServerManagerOptionScreen::closeScreen() {
	_minecraftClient->setScreen(new StartMenuScreen());
}
