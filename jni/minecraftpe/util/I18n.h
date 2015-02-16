#pragma once

class AppPlatform;

class I18n {
public:
	static void loadLanguage(AppPlatform *, std::string const&);
	static std::string get(const std::string &);
	static std::string get(const std::string &, std::string &);
};
