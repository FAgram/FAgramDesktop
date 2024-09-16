/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Statistic {

constexpr auto kRulerLineAlpha = 0.06;

struct Limits final {
	float64 min = 0;
	float64 max = 0;
};

enum class ChartViewType {
	Linear,
	Bar,
	StackBar,
	DoubleLinear,
	StackLinear,
};

} // namespace Statistic
