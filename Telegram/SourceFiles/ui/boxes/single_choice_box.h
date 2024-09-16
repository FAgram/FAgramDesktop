/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

#include "ui/layers/generic_box.h"
#include "base/required.h"

namespace style {
struct Checkbox;
struct Radio;
} // namespace style

struct SingleChoiceBoxArgs {
	template <typename T>
	using required = base::required<T>;

	required<rpl::producer<QString>> title;
	const std::vector<QString> &options;
	int initialSelection = 0;
	required<Fn<void(int)>> callback;
	const style::Checkbox *st = nullptr;
	const style::Radio *radioSt = nullptr;
};

void SingleChoiceBox(
	not_null<Ui::GenericBox*> box,
	SingleChoiceBoxArgs &&args);
