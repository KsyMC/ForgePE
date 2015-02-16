#include "minecraftpe/Minecraft.h"
#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/util/Util.h"
#include "minecraftpe/util/Token.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/tile/TilePos.h"
#include "minecraftpe/item/Item.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/network/RakNetInstance.h"
#include "minecraftpe/network/ServerSideNetworkHandler.h"
#include "minecraftpe/network/packet/MovePlayerPacket.h"
#include "minecraftpe/network/packet/ChatPacket.h"
#include "minecraftpe/network/packet/SetSpawnPositionPacket.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/command/ServerCommandParser.h"
#include "shared.h"

/*void ServerCommandParser::addOp(const string &name) {
	if(!playerIsOp(name)) {
		ServerCommandParser::_opList.push_back(Util::toLower(name));
	}
}

void ServerCommandParser::addBan(const string &name) {
	if(!playerIsBanned(name)) {
		ServerCommandParser::_banList.push_back(Util::toLower(name));
	}
}

void ServerCommandParser::removeOp(const string &name) {
	if(playerIsOp(name)) {
		vector<string>::iterator result = find(ServerCommandParser::_opList.begin(), ServerCommandParser::_opList.end(), Util::toLower(name));
		ServerCommandParser::_opList.erase(result);
	}
}

void ServerCommandParser::pardon(const string &name) {
	if(playerIsBanned(name)) {
		vector<string>::iterator result = find(ServerCommandParser::_banList.begin(), ServerCommandParser::_banList.end(), Util::toLower(name));
		ServerCommandParser::_banList.erase(result);
	}
}

bool ServerCommandParser::playerIsOp(const string &name) {
	vector<string>::iterator result = find(ServerCommandParser::_opList.begin(), ServerCommandParser::_opList.end(), Util::toLower(name));
	if(result != ServerCommandParser::_opList.end()) {
		return true;
	}

	return false;
}

bool ServerCommandParser::playerIsBanned(const string &name) {
	vector<string>::iterator result = find(ServerCommandParser::_banList.begin(), ServerCommandParser::_banList.end(), Util::toLower(name));
	if(result != ServerCommandParser::_banList.end()) {
		return true;
	}

	return false;
}

string ServerCommandParser::sendMessage(Minecraft *minecraft, Player *player, const string &result) {
	if(player->isLocalPlayer()) {
		return result;
	}

	ChatPacket packet;
	packet._chat = result;
	minecraft->_raknetInstance->send(player->_playerGUID, packet);

	return "";
}

string ServerCommandParser::_ban(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/ban <플레이어> [이유...]");
	}

	const string &name = args[1].getText(Util::EMPTY_STRING);
	string reason;

	if(args.size() == 3) {
		reason = args[2].getText(Util::EMPTY_STRING);
	}

	Player *target = level->getPlayer(name);
	if(target) {
		target->remove();
	}
	addBan(name);
	networkHandler->displayGameMessage("server", "플레이어 " + name + "을(를) 차단했습니다" + (reason.empty() ? "" : (": '" + reason + "'")));

	return "";
}

string ServerCommandParser::_banlist(Minecraft *minecraft, const vector<Token> &args) {
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	string cmd;

	if(args.size() == 2) {
		cmd = args[1].getText(Util::EMPTY_STRING);
	}

	if(!cmd.compare("ips")) {
		sendMessage(minecraft, senderPlayer, "총 " + Util::toString((int) 0) + "개의 차단된 IP 주소가 있습니다:");
	} else if(!cmd.compare("") || !cmd.compare("players")) {
		sendMessage(minecraft, senderPlayer, "총 " + Util::toString((int) ServerCommandParser::_banList.size()) + "명의 차단된 플레이어가 있습니다:");
		for(int i = 0; i < ServerCommandParser::_banList.size(); i++) {
			sendMessage(minecraft, senderPlayer, ServerCommandParser::_banList[i]);
		}
	}

	return "";
}

string ServerCommandParser::_pardon(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	const string &name = args[1].getText(Util::EMPTY_STRING);

	if(!playerIsOp(senderPlayer->_playerName)) {
			return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/pardon <플레이어>");
	}
	pardon(name);
	networkHandler->displayGameMessage("server", "플레이어 " + name + "의 차단을 해제하였습니다");

	return "";
}

string ServerCommandParser::_time(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/time <set|add> <값> 또는 /time <start|stop>");
	}

	const string &cmd = args[1].getText(Util::EMPTY_STRING);
	if(!cmd.compare("add")) {
		if(args.size() != 3 || args[2]._type != 1) {
			return sendMessage(minecraft, senderPlayer, "/time add <값>");
		}
		level->setTime(level->getTime() + args[2].getValue(0));
		networkHandler->displayGameMessage("server", "시간을 추가하였습니다");

		return "";
	} else if(!cmd.compare("set")) {
		if(args.size() != 3) {
			return sendMessage(minecraft, senderPlayer, "/time <set> <값> 또는 /time <set> <day|sunset|night|sunrise>");
		}

		if(args[2]._type == 1) {
			int time = args[2].getValue(0);
			level->setTime(time);
			networkHandler->displayGameMessage("server", "시간을 " + Util::toString(time) + "(으)로 변경하였습니다");

			return "";
		} else {
			const string &value = args[2].getText(Util::EMPTY_STRING);
			if(!value.compare("day")) {
				level->setTime(0);
			} else if(!value.compare("sunset")) {
				level->setTime(12000);
			} else if(!value.compare("night")) {
				level->setTime(14000);
			} else if(!value.compare("sunrise")) {
				level->setTime(23000);
			} else {
				return sendMessage(minecraft, senderPlayer, "/time <set> <day|sunset|night|sunrise>");
			}
			networkHandler->displayGameMessage("server", "시간을 " + value + "(으)로 변경하였습니다");

			return "";
		}
	} else if(!cmd.compare("start")) {
		level->setDayCycleActive(true);
		networkHandler->displayGameMessage("server", "시간을 다시 시작했습니다");

		return "";
	} else if(!cmd.compare("stop")) {
		level->setDayCycleActive(false);
		networkHandler->displayGameMessage("server", "시간을 멈췄습니다");

		return "";
	}
	return sendMessage(minecraft, senderPlayer, "/time <set|add> <값> 또는 /time <start|stop>");
}

string ServerCommandParser::_kill(Minecraft *minecraft, const vector<Token> &args) {
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	string name = args[0].getText(Util::EMPTY_STRING);

	if(args.size() == 2) {
		if(!playerIsOp(senderPlayer->_playerName)) {
			return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
		}
		name = args[1].getText(Util::EMPTY_STRING);
	}

	Player *player = minecraft->_level->getPlayer(name);
	if(!player) {
		return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
	}
	player->hurt(NULL, 20);
	return sendMessage(minecraft, player, "Ouch. That look like it hurt");
}

string ServerCommandParser::_op(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/op <플레이어>");
	}

	const string &name = args[1].getText(Util::EMPTY_STRING);
	if(playerIsOp(name)) {
		return sendMessage(minecraft, senderPlayer, "이미 권한이 있습니다");
	}
	addOp(name);
	networkHandler->displayGameMessage("server", name + "에게 관리자 권한을 주었습니다");

	return "";
}

string ServerCommandParser::_deop(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/deop <플레이어>");
	}

	const string &name = args[1].getText(Util::EMPTY_STRING);
	if(!playerIsOp(name)) {
		return sendMessage(minecraft, senderPlayer, "그 플레이어는 오피가 아닙니다");
	}
	removeOp(name);
	networkHandler->displayGameMessage("server", name + "의 관리자 권한을 박탈하였습니다");

	return "";
}

string ServerCommandParser::_teleport(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(args.size() == 4) {
		if(args[1]._type != 1 || args[2]._type != 1 || args[3]._type != 1) {
			return sendMessage(minecraft, senderPlayer, "/tp <x> <y> <z>");
		}

		float x = args[1].getValue(0);
		float y = args[2].getValue(0);
		float z = args[3].getValue(0);

		if(!senderPlayer->isLocalPlayer()) {
			MovePlayerPacket movePlayerPacket;
			movePlayerPacket._eid = senderPlayer->_eid;
			movePlayerPacket._x = x;
			movePlayerPacket._y = y;
			movePlayerPacket._z = z;
			movePlayerPacket._bodyYaw = 0;
			movePlayerPacket._yaw = 0;
			movePlayerPacket._pitch = 0;
			movePlayerPacket._teleport = true;

			minecraft->_raknetInstance->send(movePlayerPacket);
		}
		senderPlayer->teleportTo(x, y, z);
		networkHandler->displayGameMessage("server", senderPlayer->_playerName + "이(가) " + Util::toString(x) + ", " + Util::toString(y) + ", " + Util::toString(z) + "으로 순간이동 했습니다");

		return "";
	} else if(args.size() == 5) {
		if(!playerIsOp(senderPlayer->_playerName)) {
			return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
		}else if(args[2]._type != 1 || args[3]._type != 1 || args[4]._type != 1) {
			return sendMessage(minecraft, senderPlayer, "/tp [이동시킬 플레이어] <x> <y> <z>");
		}

		Player *player = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
		if(!player) {
			return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
		}

		float x = args[2].getValue(0);
		float y = args[3].getValue(0);
		float z = args[4].getValue(0);

		if(!player->isLocalPlayer()) {
			MovePlayerPacket movePlayerPacket;
			movePlayerPacket._eid = player->_eid;
			movePlayerPacket._x = x;
			movePlayerPacket._y = y;
			movePlayerPacket._z = z;
			movePlayerPacket._bodyYaw = 0;
			movePlayerPacket._yaw = 0;
			movePlayerPacket._pitch = 0;
			movePlayerPacket._teleport = true;

			minecraft->_raknetInstance->send(movePlayerPacket);
		}
		player->teleportTo(x, y, z);
		networkHandler->displayGameMessage("server", senderPlayer->_playerName + "이(가) " + player->_playerName + "을(를) " + Util::toString(x) + ", " + Util::toString(y) + ", " + Util::toString(z) + "에게로 순간이동 시켰습니다");
	} else if(args.size() == 3) {
		if(!playerIsOp(senderPlayer->_playerName)) {
			return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
		}

		Player *player = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
		Player *target = level->getPlayer(args[2].getText(Util::EMPTY_STRING));
		if(!player || !target) {
			return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
		}

		if(!player->isLocalPlayer()) {
			MovePlayerPacket movePlayerPacket;
			movePlayerPacket._eid = player->_eid;
			movePlayerPacket._x = target->_x;
			movePlayerPacket._y = target->_y;
			movePlayerPacket._z = target->_z;
			movePlayerPacket._bodyYaw = 0;
			movePlayerPacket._yaw = 0;
			movePlayerPacket._pitch = 0;
			movePlayerPacket._teleport = true;

			minecraft->_raknetInstance->send(movePlayerPacket);
		}
		player->teleportTo(target->_x, target->_y, target->_z);
		networkHandler->displayGameMessage("server", senderPlayer->_playerName + "이(가) " + player->_playerName + "을(를) " + target->_playerName + "에게로 순간이동 했습니다");

		return "";
	} else if(args.size() == 2) {
		Player *target = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
		if(!target) {
			return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
		}

		if(!senderPlayer->isLocalPlayer()) {
			MovePlayerPacket movePlayerPacket;
			movePlayerPacket._eid = senderPlayer->_eid;
			movePlayerPacket._x = target->_x;
			movePlayerPacket._y = target->_y;
			movePlayerPacket._z = target->_z;
			movePlayerPacket._bodyYaw = 0;
			movePlayerPacket._yaw = 0;
			movePlayerPacket._pitch = 0;
			movePlayerPacket._teleport = true;

			minecraft->_raknetInstance->send(movePlayerPacket);
		}
		senderPlayer->teleportTo(target->_x, target->_y, target->_z);
		networkHandler->displayGameMessage("server", senderPlayer->_playerName + "이(가) " + target->_playerName + "에게 순간이동 했습니다");

		return "";
	}
	return sendMessage(minecraft, senderPlayer, "/tp [이동시킬 플레이어] <목표할 플레이어> 또는 /tp [이동시킬 플레이어] <x> <y> <z>");
}

string ServerCommandParser::_setWorldSpawn(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() == 4 && (args[1]._type != 1 || args[2]._type != 1 || args[3]._type != 1)) {
		return sendMessage(minecraft, senderPlayer, "/setworldspawn [<x> <y> <z>]");
	}

	TilePos tilePos(senderPlayer->_x, senderPlayer->_y, senderPlayer->_z);

	if(args.size() == 4) {
		tilePos._x = args[1].getValue(0);
		tilePos._y = args[2].getValue(0);
		tilePos._z = args[3].getValue(0);
	}
	level->setDefaultSpawn(tilePos);

	SetSpawnPositionPacket packet;
	packet._tilePos = tilePos;
	minecraft->_raknetInstance->send(packet);

	networkHandler->displayGameMessage("server", "세계의 스폰 지점을 (" + Util::toString(tilePos._x) + ", " + Util::toString(tilePos._y) + ", " + Util::toString(tilePos._z) + ")로 설정했습니다");

	return "";
}

string ServerCommandParser::_spawnPoint(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	TilePos tilePos(senderPlayer->_x, senderPlayer->_y, senderPlayer->_z);
	string name;

	if(args.size() == 5) {
		if(args[2]._type != 1 || args[3]._type != 1 || args[4]._type != 1) {
			return sendMessage(minecraft, senderPlayer, "/spawnpoint [플레이어] 또는 /spawnpoint [플레이어] [<x> <y> <z>]");
		}

		Player *target = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
		if(!target) {
			return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
		}

		tilePos._x = args[2].getValue(0);
		tilePos._y = args[3].getValue(0);
		tilePos._z = args[4].getValue(0);
		target->setRespawnPosition(tilePos);

		name = target->_playerName;
	} else if(args.size() == 2) {
		Player *target = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
		if(!target) {
			return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
		}

		tilePos._x = target->_x;
		tilePos._y = target->_y;
		tilePos._z = target->_z;
		target->setRespawnPosition(tilePos);

		name = target->_playerName;
	} else {
		tilePos._x = senderPlayer->_x;
		tilePos._y = senderPlayer->_y;
		tilePos._z = senderPlayer->_z;
		senderPlayer->setRespawnPosition(tilePos);

		name = senderPlayer->_playerName;
	}
	networkHandler->displayGameMessage("server", name + "의 리스폰 지점을 (" + Util::toString(tilePos._x) + ", " + Util::toString(tilePos._y) + ", " + Util::toString(tilePos._z) + ")으로 설정하였습니다");

	return "";
}

string ServerCommandParser::_say(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/say <메시지...>");
	}
	networkHandler->displayGameMessage("server", "§5" + args[1].getText(Util::EMPTY_STRING));

	return "";
}

string ServerCommandParser::_pvp(Minecraft *minecraft, const vector<Token> &args) {
	ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Player *senderPlayer = minecraft->_level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, "/pvp <on|off>");
	}

	bool enable;

	if(args[1]._type == 1) {
		enable = args[1].getValue(0) == 1;
	} else {
		const string &text = args[1].getText(Util::EMPTY_STRING);
		enable = !text.compare("true") || !text.compare("on");
	}
	ServerCommandParser::_enablePVP = enable;
	networkHandler->displayGameMessage("server", "PVP가 " + string(enable ? "켜졌습니다" : "금지되었습니다"));

	return "";
}*/
