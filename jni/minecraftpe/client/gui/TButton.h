#pragma once

#include "minecraftpe/client/gui/Button.h"

namespace Touch {
class TButton : public Button {
public:
	// Size : 128
	void *_ninepathLayer1;		// 120
	void *_ninepathLayer2;		// 124

public:
	TButton(int, int, int, int, int, const std::string &);
	TButton(int, int, int, const std::string &, MinecraftClient *);
	TButton(int, const std::string &, MinecraftClient *, bool);
	virtual ~TButton();
	virtual void renderBg(MinecraftClient *, int, int);
	void init(MinecraftClient *);
};
}
