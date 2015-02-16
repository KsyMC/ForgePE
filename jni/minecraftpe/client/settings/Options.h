#pragma once

class Options {
public:
	class Option {
	public:
		/*static void GAMMA, LIMIT_WORLD_SIZE, NAME, PIXELS_PER_MILLIMETER, ANIMATE_TEXTURES;
		static void FANCY_SKIES, DESTROY_VIBRATION, USE_TOUCH_JOYPAD, USE_TOUCHSCREEN;
		static void LEFT_HANDED, SERVER_VISIBLE, HIDE_GUI, THIRD_PERSON, GUI_SCALE, GRAPHICS;
		static void DIFFICULTY, LIMIT_FRAMERATE, VIEW_BOBBING, VIEW_DISTANCE, SENSITIVITY;
		static void INVERT_MOUSE, SOUND, MUSIC;*/
		~Option();
	};

public:
	/*static void RENDERDISTANCE_LEVELS_LOMEM, RENDERDISTANCE_LEVELS_256PLUS, RENDERDISTANCE_LEVELS_512PLUS;
	static void DIFFICULTY_LEVELS;
	static float PIXELS_PER_MILLIMETER_MAX_VALUE, PIXELS_PER_MILLIMETER_MIN_VALUE;
	static float SENSITIVITY_MAX_VALUE, SENSITIVITY_MIN_VALUE;
	static float MUSIC_MAX_VALUE, MUSIC_MIN_VALUE;
	static float SOUND_MAX_VALUE, SOUND_MIN_VALUE;*/
	static void *debugGl;

public:
	float _music;				// 0
	float _sound;				// 4
	float _sensitivity;			// 8
	char filler1[4];			// 12
	bool _invertMouse;			// 16
	int _viewDistance;			// 20
	bool _viewBobbing;			// 24
	bool _limitFramerate;		// 25
	bool _graphics;				// 26
	char filler2[2];			// 27
	bool _leftHanded;			// 29
	bool _destroyVibration;		// 30
	char filler3[205];			// 31
	int _difficulty;			// 236
	bool _hideGUI;				// 240
	bool _thirdPerson;			// 241
	float _gamma;				// 244
	char filler4[16];			// 248
	std::string _name;			// 264
	bool _serverVisible;		// 268
	bool _useTouchJoypad;		// 269
	bool _useTouchScreen;		// 270
	bool _fancySkies;			// 271
	bool _animateTextures;		// 272
	char filler5[19];			// 273
	float _pixelsPerMillimeter;	// 292
	bool _limitWorldSize;		// 299


};
