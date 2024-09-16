/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "settings/settings_type.h"

namespace Ui {
class GenericBox;
} // namespace Ui

namespace Settings {

[[nodiscard]] Type QuickRepliesId();

void EditShortcutNameBox(
	not_null<Ui::GenericBox*> box,
	QString name,
	Fn<void(QString, Fn<void()>)> submit);

} // namespace Settings
