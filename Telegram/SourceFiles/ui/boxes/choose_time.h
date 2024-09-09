/*
This file is part of FAgram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/object_ptr.h"

namespace Ui {

class RpWidget;

struct ChooseTimeResult {
	object_ptr<RpWidget> widget;
	rpl::producer<TimeId> secondsValue;
};

ChooseTimeResult ChooseTimeWidget(
	not_null<RpWidget*> parent,
	TimeId startSeconds);

} // namespace Ui
