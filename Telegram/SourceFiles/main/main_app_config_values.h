/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Main {
class Session;
} // namespace Main

namespace AppConfig {

[[nodiscard]] std::optional<QString> FragmentLink(not_null<Main::Session*>);

} // namespace AppConfig
