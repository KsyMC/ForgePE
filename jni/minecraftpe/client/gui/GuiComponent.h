#pragma once

#include "minecraftpe/client/gui/ScreenRenderer.h"

class GuiComponent {
public:
	// Size : 64
	//void **vtable;				// 0
	ScreenRenderer _screenRenderer;	// 4

	GuiComponent();
	virtual ~GuiComponent();
};
