#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <map>
#include <string>

struct Theme {
    std::string backgroundColor;
    std::string blockColor;
    std::string textColor;
};

class ThemeManager {
public:
    ThemeManager();
    void switchTheme(const std::string& themeName);
    void customizeTheme(const std::string& themeName, const Theme& newTheme);
    const Theme& getCurrentTheme() const;

private:
    std::map<std::string, Theme> themes;
    std::string currentTheme;
};

#endif // THEME_MANAGER_H
