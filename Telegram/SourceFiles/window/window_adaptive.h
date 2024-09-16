/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Window {

class Adaptive {
public:
	enum class WindowLayout {
		OneColumn,
		Normal,
		ThreeColumn,
	};

	enum class ChatLayout {
		Normal,
		Wide,
	};

	Adaptive();

	void setWindowLayout(WindowLayout value);
	void setChatLayout(ChatLayout value);

	[[nodiscard]] rpl::producer<> value() const;
	[[nodiscard]] rpl::producer<> changes() const;
	[[nodiscard]] rpl::producer<bool> oneColumnValue() const;
	[[nodiscard]] rpl::producer<ChatLayout> chatLayoutValue() const;

	[[nodiscard]] bool isOneColumn() const;
	[[nodiscard]] bool isNormal() const;
	[[nodiscard]] bool isThreeColumn() const;

	[[nodiscard]] rpl::producer<bool> chatWideValue() const;
	[[nodiscard]] bool isChatWide() const;

private:
	rpl::variable<ChatLayout> _chatLayout;
	rpl::variable<WindowLayout> _layout;

};

} // namespace Window
