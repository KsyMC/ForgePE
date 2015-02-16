#include "minecraftpe/util/Util.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/client/AppPlatform.h"
#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/command/ICommandManager.h"
#include "minecraftpe/client/gui/ChatScreen.h"
#include "minecraftpe/entity/player/LocalPlayer.h"
#include "shared.h"
#include "Substrate.h"

ChatScreen::SendChatMessageReal ChatScreen::sendChatMessage_real;

using std::string;

void ChatScreen::initHooks(void *handle) {
	MSHookFunction((void *) &ChatScreen::sendChatMessage,	(void *) &ChatScreen::sendChatMessage_hook,	(void **) &ChatScreen::sendChatMessage_real);
}

void ChatScreen::sendChatMessage_hook() {
	string message = _message;
	if(!_minecraftClient->isOnlineClient() && message.length() > 0 && Util::startsWith(message, "/")) {
		ICommandManager *commandManager = _minecraftClient->getCommandManager();
		commandManager->executeCommand(_minecraftClient->getLocalPlayer(), message);

		_message = "";
		_minecraftClient->platform()->updateTextBoxText(_message);

		return;
	}
	ChatScreen::sendChatMessage_real(this);
}
