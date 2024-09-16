/*
This file is part of FAgram Desktop,
the unofficial desktop client based on Telegram Desktop.

For license and copyright information please follow this link:
https://github.com/fajox1/fagramdesktop/blob/master/LEGAL
*/
#pragma once

namespace Statistic {

class AbstractChartView;
enum class ChartViewType;

[[nodiscard]] std::unique_ptr<AbstractChartView> CreateChartView(
	ChartViewType type);

} // namespace Statistic
