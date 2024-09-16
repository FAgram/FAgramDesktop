/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Platform::AutostartTask {

void Toggle(bool enabled, Fn<void(bool)> done);
void RequestState(Fn<void(bool)> callback);
void OpenSettings();

} // namespace Platform::AutostartTask
