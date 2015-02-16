#pragma once

#include "minecraftpe/client/gui/Button.h"

namespace Touch {
class THeader : public Button {
public:
	// Size : 124
	char filler1[4];	// 120

	THeader(int, int, int, int, int, const std::string &);
	THeader(int, int, int, const std::string &);
	THeader(int, const std::string &);
	virtual ~THeader();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
};
}
