#pragma once

#include "minecraftpe/client/gui/Button.h"

class BlankButton : public Button {
public:
	// Size : 120

public:
	BlankButton(int);
	BlankButton(int, int, int, int);
	virtual ~BlankButton();
};
